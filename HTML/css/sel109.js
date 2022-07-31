document.getElementById("demo").addEventListener("click",MyFunction1);

function MyFunction1(){
    let text = "Press a button ! \n Either Name or Title.";
  if(confirm(text)==true){
     text = "You pressed Name";
  }
  else{
    text = "You cancelled";
  }
  document.getElementById("span").innerHTML=text;
}


const collection = document.getElementsByTagName("p").addEventListener("click",MyFunction2);

function MyFunction2(){
   let text = "i cant provide personal data";
   collection[1]=text;
    document.getElementById("demo").innerHTML = collection[1].innerHTML;
}