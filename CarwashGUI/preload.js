const { contextBridge, ipcRenderer } = require('electron')
const fs = require('fs')

/**
 * Checks if a string starts with any of the strings passed.
 * @param {*} str the string to check
 * @param {*} substrs a set of starting points
 * @returns returns true if any of the substrings are
 * 			present at the start of the given string
 */
function stringStartsWith(string, stringSet) {
	return stringSet.some(substr => string.startsWith(substr));
}

/**
 * Common namespace API for safe filesystem interactions.
 */
const fsInteraction = {
	/**
	 * Paths that are allowed to be used by the filesystem api.
	 */
	allowedPaths: ["./", "./assets/"],
	/**
	 * Blocking operation that reads a file and returns it's content.
	 * @param {*} pathToFile path and filename
	 * @param {*} encoding encoding of the file
	 * @returns the contents of the file
	 */
	synchronizedRead: (pathToFile, encoding) => {
		if (stringStartsWith(pathToFile, fsInteraction.allowedPaths)) {
			return fs.readFileSync(pathToFile, encoding)
		} else {
			return ""
		}
	}
}

const appInteraction = {
	interProcessRenderer: ipcRenderer
}

contextBridge.exposeInMainWorld("internalApis", {
	fsInteraction: fsInteraction,
	appInteraction: appInteraction
})
