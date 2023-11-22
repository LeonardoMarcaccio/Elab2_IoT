const { app, BrowserWindow, ipcMain } = require('electron')
const path = require('node:path')

var win

// Creates a window using the main page
const createWindow = () => {
    win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            sandbox: false,
            preload: path.join(__dirname, 'preload.js')
        },
        icon: "./assets/images/carwash.ico",
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

ipcMain.on("application-quit", () => {
    app.quit()
})
ipcMain.on("application-resize", () => {
    if (win.isMaximized()) {
        win.unmaximize()
    } else {
        win.maximize()
    }
})
ipcMain.on("application-iconify", () => {
    if (win.isMinimized()) {
        win.unminimize()
    } else {
        win.minimize()
    }
})