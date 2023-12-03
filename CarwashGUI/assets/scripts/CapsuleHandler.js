let CapsuleHandlerConsts = {
    identifierStart: '__CB_'
}

class CapsuleManager {
    constructor() {
        this.children = []
        this.nodevar = document.createElement('div')
        this.nodevar.className = 'ModuleContainer'
    }

    init(docToInjectTo) {
        docToInjectTo.appendChild(nodevar)
    }

    registerCapsule(capsule) {
        this.nodevar.appendChild(capsule.getNode())
        this.children.push(capsule)
    }
}

class Capsule {
    constructor(identifier, title, content) {
        this.identifier = identifier
        this.title = title
        this.content = content

        this.nodevar = document.createElement('div')
        this.nodevar.className = 'ContentBox'
        this.nodevar.id = CapsuleHandlerConsts.identifierStart + this.identifier

        let boxTopBar = document.createElement('div')
        boxTopBar.className = 'ContentBoxTopBar'
        let boxContent = document.createElement('div')
        boxTopBar.className = 'ContentBoxBody'

        this.nodevar.appendChild(boxTopBar)
        this.nodevar.appendChild(boxContent)
    }

    getNode() {
        return this.nodevar
    }
}
