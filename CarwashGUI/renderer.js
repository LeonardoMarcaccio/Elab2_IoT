document.body.onload = () => initGUI()

let manager
let COMController

function initTopBarArea() {
    let nelem = document.createElement('div')
    nelem.innerHTML =
        window.internalApis.fsInteraction.synchronizedRead("./assets/elements/programcontrolbar/programcontrolbar.html", "UTF-8")
    document.body.insertBefore(nelem.firstChild, document.body.firstChild)
}

function initBaseElements() {
    //initTopBarArea()
	manager = new CapsuleManager()
    manager.init(document.body)
}

function generateView() {
	var panel = document.createElement('div')
	let tempCapsule = new Capsule(0, 'ArduinoCOMs', panel)
	manager.registerCapsule(tempCapsule)
	registerListPanel(panel)
}

function initGUI() {
    initBaseElements()
	initArduinoComms()
    generateView()
}
/*//const SerialPort = window.internalApis.hwInteraction.SerialPort
//const Readline = window.internalApis.hwInteraction.SerialReadLine
const port = new SerialPort('/dev/ttyACM0', { baudRate: 9600 });
const parser = port.pipe(new SerialReadLine({ delimiter: '\n' }));
// Read the port data
port.on("open", () => {
  console.log('serial port open');
});
parser.on('data', data =>{
  console.log('got word from arduino:', data);
});


//var serialPortList = await SerialPort.list()
/*SerialPort.list().then(result => console.log(result))
const port = new SerialPort({
	path:'COM5',
	baudRate:9600
})
const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));
port.on("open", () => {
  console.log('serial port open');
});
parser.on('data', data =>{
  console.log('got word from arduino:', data);
});*/
