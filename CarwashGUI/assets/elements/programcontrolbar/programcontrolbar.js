const { ipcRenderer } = require('electron')

document.getElementById("QuitBtn").onclick(() => programControlBar.quitActionFunc())

const programControlBar = {
    quitActionFunc: () => {
        ipcRenderer.send("application-quit")
    }
}