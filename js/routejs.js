
var IO_HTTP_JS = function(){
    return "SUPER API";
}

function RouteJs(param){
   var html = component(param,IO_HTTP_JS);
   document.getElementById("c1").innerHTML = html;
   return html;
}
