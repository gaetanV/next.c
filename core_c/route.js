
var IO_HTTP;

var Module = {
    onRuntimeInitialized: function() {
        IO_HTTP = addFunction(function(s){
            param = "SUPER API";
            var buffer = Module._malloc(param.length + 1);
            stringToUTF8(param, buffer, param.length + 1);
            return buffer;
        }, 'test');
    }
};

function Route(param){
    var buffer = Module._malloc(param.length + 1);
    stringToUTF8(param, buffer, param.length + 1);
  
    response = Module._component(buffer,IO_HTTP); 
    var html = UTF8ToString(response);
    
    document.getElementById("c2").innerHTML = html;
    
    window.history.pushState({
        html: html
    }, false, param +".html");
    
}

window.onpopstate = function(oEvent) {
    state=oEvent.state;
    document.getElementById("c2").innerHTML = state.html;
};
