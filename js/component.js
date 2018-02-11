function component(param,IO_HTTP_JS){
    var html = "<p>"+ IO_HTTP_JS()+"</p>";
    for(var i of param){
        html+="<p>"+i+"</p>";
    }
    return html ;
}
