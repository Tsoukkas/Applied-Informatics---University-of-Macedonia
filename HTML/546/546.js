function add(){
    let a = document.getElementById("text").value;
   document.getElementById("demo").innerHTML +=a ;
   let width =document.getElementById("demo").offsetWidth;
   if(width == "6cm"){
    document.getElementById("demo").innerHTML += "\n" ;
   }
}