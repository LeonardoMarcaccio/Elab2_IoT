const { app, BrowserWindow, contextBridge } = require('electron')
const path = require('node:path')
const fs = require('fs')

// Creates a window using the main page
const createWindow = () => {
    const win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            sandbox: false,
            preload: path.join(__dirname, 'preload.js')
        },
        frame: false
    })
    win.loadFile('index.html')
}

// Window opening for MacOS
app.whenReady().then(() => {
    createWindow()
    app.on('activate', () => {
        if (BrowserWindow.getAllWindows().length === 0) createWindow()
    })
})

// Closes app when windows are closed
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') app.quit()
})

/*const fileSystem = {
    fsReadFile: (pathToFile, encoding) => {
        return fs.readFileSync(pathToFile, {encoding})
    }
}*/

function uniqueNameRead(pathToFile, encoding) {
    return fs.readFileSync(pathToFile, {encoding});
}
console.log("Stampa all'interno di main.js:\n"+uniqueNameRead("test.txt", "UTF-8"))
