const { contextBridge, ipcRenderer } = require('electron')
const fs = require('fs')
const { SerialPort } = require('serialport')
const { ReadlineParser } = require('@serialport/parser-readline')

let comSessions = []

/**
 * Checks if a string starts with any of the strings passed.
 * @param {*} str the string to check
 * @param {*} substrs a set of starting points
 * @returns returns true if any of the substrings are
 * 			present at the start of the given string
 */
function stringStartsWith(string, stringSet) {
	return stringSet.some(substr => string.startsWith(substr));
}

/**
 * Common namespace API for safe filesystem interactions.
 */
const fsInteraction = {
	/**
	 * Paths that are allowed to be used by the filesystem api.
	 */
	allowedPaths: ["./", "./assets/"],
	/**
	 * Blocking operation that reads a file and returns it's content.
	 * @param {*} pathToFile path and filename
	 * @param {*} encoding encoding of the file
	 * @returns the contents of the file
	 */
	synchronizedRead: (pathToFile, encoding) => {
		if (stringStartsWith(pathToFile, fsInteraction.allowedPaths)) {
			return fs.readFileSync(pathToFile, encoding)
		} else {
			return ""
		}
	}
}

const appInteraction = {
	interProcessRenderer: ipcRenderer
}

/*const comInteraction = {
	listConnectedDevices: () => {
		return SerialPort.list()
	},
	startConnection: (path, baudRate, openFunc, dataFunc) => {
		const serialConnPort = new SerialPort({
			path:path,
			baudRate:baudRate
		})
		const dataParser = serialConnPort.pipe(
			new ReadlineParser({ delimiter: '\n' }))
		serialConnPort.on("open", () => {
			openFunc()
		});
		dataParser.on('data', (data) =>{
			dataFunc(data)
		});
	}
}*/

const comManager = {
	listConnectedDevices: () => {
		return SerialPort.list()
	},
	generateComSession: (path, baudrate, openFunc, dataFunc) => {
		let ses = new COMSession(path, baudrate, openFunc, dataFunc)
		comSessions.push(ses)
		return comSessions.indexOf(ses)
	},
	startComSession: (sessionId) => {
		comSessions[sessionId].startConnection()
	},
	sendMessageToComSession: (sessionId, data, errorHandler) => {
		comSessions[sessionId].sendMessage(data, errorHandler)
	}
}

class COMSession {
	constructor(path, baudrate, openFunc, dataFunc) {
		this.path = path
		this.baudrate = baudrate
		this.openFunc = openFunc
		this.dataFunc = dataFunc
	}

	startConnection() {
		this.serialConnPort = new SerialPort({
			path:this.path,
			baudRate:this.baudrate
		})
		const dataParser = this.serialConnPort.pipe(
			new ReadlineParser({ delimiter: '\n' }))
			this.serialConnPort.on("open", () => {
			this.openFunc()
		});
		dataParser.on('data', (data) =>{
			this.dataFunc(data)
		});
	}
	
	sendMessage(data, errorHandler) {
		this.serialConnPort.write(data, function(error) {
			if (error) {
			  return console.log('Error on write: ', err.message)
			}
		  })
	}
}

contextBridge.exposeInMainWorld("internalApis", {
	fsInteraction: fsInteraction,
	appInteraction: appInteraction,
	comManager: comManager
})

//var serialPortList = await SerialPort.list()
/*SerialPort.list().then(result => console.log(result))
const porta = new SerialPort({
	path:'COM5',
	baudRate:9600
})
const parsere = porta.pipe(new ReadlineParser({ delimiter: '\n' }));
porta.on("open", () => {
  console.log('serial port open');
});
parsere.on('data', data =>{
  console.log('got word from arduino:', data);
});*/