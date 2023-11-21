
const titleBar = {
    add: function init() {
        var header = fileSystem.readFile("./assets/pages/titlebar.html");
        var body = document.getElementsByName("body")
        body.forEach(x => x.appendChild(header))
    }
}