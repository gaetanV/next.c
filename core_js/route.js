
var IO_HTTP_JS = function(){
    return "SUPER API";
}

function Route(param) {
   var html = component(param,IO_HTTP_JS);
   document.getElementById("c1").innerHTML = html;
   window.history.pushState({
        html: html
   }, false, param +".html");
}

window.onpopstate = function(oEvent) {
    state=oEvent.state;
    document.getElementById("c1").innerHTML = state.html;
};