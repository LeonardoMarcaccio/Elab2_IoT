let listPanel
let deviceListCache = []

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
        //deviceEntryElement.appendChild(document.createElement("br"))
        deviceEntryElement.appendChild(deviceDetail)
        //deviceEntryElement.appendChild(document.createElement("br"))
        deviceEntryElement.appendChild(deviceConnectBtn)
        listPanel.appendChild(deviceEntryElement)
    })
}

function registerListPanel(element) {
    console.log("listpanelregistered")
    listPanel = element
}

function initArduinoComms() {
    window.setInterval(fireDeviceScan, arduinoCOMsConstants.deviceScanInterval)
}

function openConnection(pathto, baudrate) {
    console.log("Firing connection on port "+pathto+" with baudrate at: "+baudrate)
    /*var port = window.internalApis.comInteraction.createSerialPort({
        path:pathto,
        baudRate:baudrate
    })*/
    window.internalApis.comInteraction.startConnection(pathto, baudrate, () => {
        console.log("Connection open")
    },
    (data) => {
        console.log(data)
    })
}
