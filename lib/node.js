var fs = require("fs");
var io = fs.readFileSync(__dirname + '/../lib/io.js');
var data = fs.readFileSync(__dirname + '/../js/component.js');
eval(io.toString() + ";" + data.toString());
console.log(component(process.argv[2],IO_HTTP_JS));