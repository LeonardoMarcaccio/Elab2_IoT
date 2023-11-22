document.getElementById("IconifyBtn").onclick = () => programControlBar.iconifyActionFunc()
document.getElementById("ResizeBtn").onclick = () => programControlBar.resizeActionFunc()
document.getElementById("QuitBtn").onclick = () => programControlBar.quitActionFunc()

const programControlBar = {
    quitActionFunc: () => {
        window.internalApis.appInteraction.interProcessRenderer.send("application-quit")
    },
    resizeActionFunc: () => {
        window.internalApis.appInteraction.interProcessRenderer.send("application-resize")
    },
    iconifyActionFunc: () => {
        window.internalApis.appInteraction.interProcessRenderer.send("application-iconify")
    },
    setProgramTitle: (label) => {
        document.getElementById("ProgramLabel").innerHTML = label
    }
}