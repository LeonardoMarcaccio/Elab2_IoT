const { contextBridge, ipcRenderer } = require('electron')
const fs = require('fs')

contextBridge.exposeInMainWorld('versions', {
    node: () => process.versions.node,
    chrome: () => process.versions.chrome,
    electron: () => process.versions.electron
    // we can also expose variables, not just functions
  })

  /*contextBridge.exposeInMainWorld('fileSystem', {
    readFile: (pathToFile, encoding) => fileSystem.fsReadFile(pathToFile, encoding)
  })*/
contextBridge.exposeInMainWorld("ugly", {
  uglyFunction: (fileName, encoding) => uniqueNameRead(fileName, encoding)
})
console.log("Stampa all'interno di preload.js, registrato il metodo nel contextbridge")
//console.log(uniqueNameRead("test.txt", "UTF-8"))
//console.log(window.ugly.uglyFunction("test.txt", "UTF-8"))

console.log(fs.readFileSync("test.txt", "UTF-8"))