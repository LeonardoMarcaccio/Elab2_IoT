let listPanel
let deviceListCache = []

/*class Arduino {
    constructor(identifier, path, baudrate) {
        this.identifier = identifier
        this.path = path
        this.baudrate = baudrate
    }
}*/

const arduinoCOMsConstants = {
    deviceScanInterval: 1000,
    deviceEntryElementPrefix: '__COME_'
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
            openConnection(device.path, 9600)
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

function openConnection(pathto, baudrate) {
    var loggerElement = document.createElement("p")
    var loggerCapsule = new Capsule(1, "Logger", loggerElement)
    loggerCapsule.getBody().style = "overflow: auto;"
    getCapsuleManager().registerCapsule(loggerCapsule)
    console.log("Firing connection on port "+pathto+" with baudrate at: "+baudrate)
    /*var port = window.internalApis.comInteraction.createSerialPort({
        path:pathto,
        baudRate:baudrate
    })*/
    window.internalApis.comInteraction.startConnection(pathto, baudrate, () => {
        console.log("Connection open")
    },
    (data) => {
        loggerCapsule.getBody().innerHTML += data+"</br>"
        levelZeroParser(data)
    })
}
