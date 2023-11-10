const { app, BrowserWindow } = require('electron')
const path = require('node:path')

// Creates a window using the main page
const createWindow = () => {
    const win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            preload: path.join(__dirname, 'preload.js')
        }
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
