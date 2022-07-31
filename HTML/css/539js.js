var x=100,y=150;
function pos(dx,dy){
    x+=30*dx;
    y+=30*dy;
    let a = document.getElementById("demo");
    a.style.top = y+ "px";
    a.style.left =x+ "px";    
}
function Show(){
    let obj = document.getElementById("demo");
    obj.style.display = "block";
}
function Hide(){
    let obj = document.getElementById("demo");
    obj.style.display = "none";
}