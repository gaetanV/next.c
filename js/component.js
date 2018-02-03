function component(param){
    var html = "";
    for(var i of param){
        html+="<p>"+i+"</p>";
    }
    return html ;
}
