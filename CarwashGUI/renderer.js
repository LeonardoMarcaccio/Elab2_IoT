document.body.onload = () => initGUI()

function initTopBarArea() {
    var nelem = document.createElement('div')
    nelem.innerHTML =
        window.internalApis.fsInteraction.synchronizedRead("./assets/elements/programcontrolbar/programcontrolbar.html", "UTF-8")
    document.body.insertBefore(nelem.firstChild, document.body.firstChild)
}

function initBaseElements() {
    //initTopBarArea()
}

function generateView() {
    
}

function initGUI() {
    initBaseElements()
    generateView()
}
