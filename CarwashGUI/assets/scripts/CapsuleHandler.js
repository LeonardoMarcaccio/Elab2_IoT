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
        docToInjectTo.appendChild(this.nodevar)
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
        boxTopBar.innerHTML = this.title
        let boxContent = document.createElement('div')
        boxContent.className = 'ContentBoxBody'

        if (content instanceof HTMLElement) {
            boxContent.appendChild(content)
        } else {
            boxContent.innerHTML = content
        }

        this.nodevar.appendChild(boxTopBar)
        this.nodevar.appendChild(boxContent)
    }

    getNode() {
        return this.nodevar
    }
}
