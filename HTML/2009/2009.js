function f1(val){
    document.getElementById("text").value+=val;
}

function f2(){
    document.getElementById("text").value ="";
}

function f3(){
    document.getElementById("text").value+= ",";
}

function convert(){
     let a= document.getElementById("text").value;
     let b = a*1.609344;
     document.getElementById("miles").innerHTML = a + " " + "miles equals" + " " + b +  " " +"kilometers" 
}

