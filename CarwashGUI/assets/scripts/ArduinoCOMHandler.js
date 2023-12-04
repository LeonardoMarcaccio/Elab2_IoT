let listPanel
let deviceListCache = []
let connectedArduinos = []

class Arduino {
    constructor(identifier, path, baudrate, capsuleManager) {
        this.identifier = identifier
        this.path = path
        this.baudrate = baudrate
        this.capsuleManager = capsuleManager
        this.status = arduinoCOMsConstants.arduinoStatuses.none
        this.temp = document.createElement("h4")
        this.status = document.createElement("h4")
        this.setStatus(arduinoCOMsConstants.arduinoStatuses.none)
        this.setTemperature(arduinoCOMsConstants.defaultTempCelsius)
        this.showMonitor()
    }

    setStatus(status) {
        switch(status) {
            case arduinoCOMsConstants.arduinoStatuses.none:
                this.status.style = "color: gray"
                this.status.innerText = "Status: "+status
            break;
            case arduinoCOMsConstants.arduinoStatuses.erro:
                this.status.style = "color: red"
                this.status.innerText = "Status: "+status
            break;
            case arduinoCOMsConstants.arduinoStatuses.good:
                this.status.style = "color: green"
                this.status.innerText = "Status: "+status
            break;
            case arduinoCOMsConstants.arduinoStatuses.warn:
                this.status.style = "color: yellow"
                this.status.innerText = "Status: "+status
            break;
        }
    }

    setTemperature(temp) {
        this.temp.innerText = "Temperature: "+temp+"°C"
    }

    showMonitor() {
        this.monitorCapsule = new Capsule(this.capsuleManager.getLastFreeId(), "Arduino "+this.identifier+" Status", "")
        this.monitorCapsule.getBody().appendChild(this.status)
        this.monitorCapsule.getBody().appendChild(this.temp)
        this.capsuleManager.registerCapsule(this.monitorCapsule)
    }

    openConnection() {
        var loggerElement = document.createElement("p")
        this.loggerCapsule = new Capsule(this.capsuleManager.getLastFreeId(), "Logger "+this.identifier, loggerElement)
        this.loggerCapsule.getBody().style = "overflow: auto;"
        getCapsuleManager().registerCapsule(this.loggerCapsule)
        //console.log("Firing connection on port "+this.path+" with baudrate at: "+this.baudrate)
        window.internalApis.comInteraction.startConnection(this.path, this.baudrate, () => {
            console.log("Connection open")
        },
        (data) => {
            this.loggerCapsule.getBody().innerHTML += data+"</br>"
            levelZeroParser(data)
        })
        this.setStatus(arduinoCOMsConstants.arduinoStatuses.good)
    }
}

const arduinoCOMsConstants = {
    deviceScanInterval: 1000,
    deviceEntryElementPrefix: '__COME_',
    defaultBaudRate: 9600,
    arduinoStatuses: {
        good: "GOOD",
        warn: "WARNING",
        erro: "ERROR",
        none: "NONE"
    },
    defaultTempCelsius: 20
}

async function fireDeviceScan() {
    let promiseList = window.internalApis.comInteraction.listConnectedDevices()
	var deviceList = await promiseList
  	if (deviceList.length == 0) {
    	return
  	}
    deviceList.forEach((detectedDevice) => {
        if (detectedDevice.vendorId == "2341") {
            deviceListHandler(detectedDevice)
        }
    })
}

function deviceListHandler(detectedDevice) {
    var found = false
    deviceListCache.forEach((singleDevice) => {
        if (singleDevice.path == detectedDevice.path) {
            found = true
        }
    })
    if (!found) {
        deviceListCache.push(detectedDevice)
        buildDeviceList()
    }
}

function buildDeviceList() {
    console.log("updated")
    if (listPanel === 'undefined' || deviceListCache.length == 0) {
        return
    }

    deviceListCache.forEach(device => {
        var deviceEntryElement = document.createElement('div')
        deviceEntryElement.className = 'DeviceEntry'
        deviceEntryElement.id = arduinoCOMsConstants.deviceEntryElementPrefix
            + deviceListCache.indexOf(device)
        
        let deviceName = document.createElement("h3")
        deviceName.textContent = "Arduino"

        let deviceDetail = document.createElement("p")
        deviceDetail.innerText = "Port: " + device.path

        let deviceConnectBtn = document.createElement("button")
        deviceConnectBtn.type = "button"
        deviceConnectBtn.addEventListener("click", () => {
            var nard = new Arduino(connectedArduinos.length, device.path, arduinoCOMsConstants.defaultBaudRate, getCapsuleManager())
            nard.openConnection()
            connectedArduinos.push(nard)
        })
        deviceConnectBtn.textContent = "Connect"

        deviceEntryElement.appendChild(deviceName)
        deviceEntryElement.appendChild(deviceDetail)
        deviceEntryElement.appendChild(deviceConnectBtn)
        listPanel.appendChild(deviceEntryElement)
    })
}

function sendParserWarning() {
    console.warn("Invalid or broken data packet recieved, dumping fragments: "
        + separatedDataPacket)
}

function registerListPanel(element) {
    listPanel = element
}

function initArduinoComms() {
    window.setInterval(fireDeviceScan, arduinoCOMsConstants.deviceScanInterval)
}

function dataHandler(splicedData) {
    console.log(splicedData)
}

function faultHandler(splicedData) {
    console.log(splicedData)
}

function structureHandler() {

}

function levelOneParser(splicedData) {
    switch(splicedData[0]) {
        case "DATA":
            dataHandler(splicedData.splice(1, splicedData.length))
        break;
        case "FAULT":
            faultHandler(splicedData.splice(1, splicedData.length))
        break;
    }
}

function levelZeroParser(data) {
    let separatedDataPacket = data.split("-")
    if (separatedDataPacket[0] == "CW" && separatedDataPacket[1] == "MC") {
        levelOneParser(separatedDataPacket.splice(2, separatedDataPacket.length))
    } else {
        sendParserWarning()
    }
}
