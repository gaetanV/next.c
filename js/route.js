
function Route(param){

    window.history.pushState({
        componentJs: RouteJs(param),
        componentC: RouteC(param)
    }, false, param +".html");
}

window.onpopstate = function(oEvent) {
    state=oEvent.state;
    document.getElementById("c1").innerHTML = state.componentJs;
    document.getElementById("c2").innerHTML = state.componentC;
};

