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

    getLastFreeId() {
        return this.children.length
    }

    registerCapsule(capsule) {
        let contained = false
        this.children.forEach((registeredCap) => {
            if (registeredCap.getIdentifier() == capsule.getIdentifier()) {
                contained = true
            }
        })
        if (contained) {
            throw new Error("Id "+capsule.getIdentifier()+" was already registered!")
        }
        this.nodevar.appendChild(capsule.getNode())
        this.children.push(capsule)
    }
    unregisterCapsule(identifier) {
        let idf
        this.children.forEach((registeredCap) => {
            if (registeredCap.getIdentifier() == identifier.getIdentifier()) {
                idf = this.children.indexOf(registeredCap)
            }
        })
        if (!(idf === 'undefined')) {
            this.children.splice(idf, idf)
        }
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

        this.nodevarTitle = document.createElement('div')
        this.nodevarTitle.className = 'ContentBoxTopBar'
        this.nodevarTitle.innerHTML = this.title
        this.nodeVarBody = document.createElement('div')
        this.nodeVarBody.className = 'ContentBoxBody'

        if (content instanceof HTMLElement) {
            this.nodeVarBody.appendChild(content)
        } else {
            this.nodeVarBody.innerHTML = content
        }

        this.nodevar.appendChild(this.nodevarTitle)
        this.nodevar.appendChild(this.nodeVarBody)
    }

    getNode() {
        return this.nodevar
    }
    getTitle() {
        return this.nodevarTitle
    }
    getBody() {
        return this.nodeVarBody
    }
    getIdentifier() {
        return this.identifier
    }
}
