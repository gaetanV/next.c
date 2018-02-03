var fs = require("fs");
var data = fs.readFileSync(__dirname+'/../js/component.js');
eval(data.toString());
console.log(component(process.argv[2]));