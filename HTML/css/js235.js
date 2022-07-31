function function1(){
    document.getElementById("camera").width = 200 ;
    document.getElementById("camera").height = 200;
}

function function2(){
    document.getElementById("camera").height = 100;
    document.getElementById("camera").width =100;
}

var obj = {"video": {
    "value": "<iframe title='YouTube video player' type=\"text/html\" width='640' height='390' src='https://www.youtube.com/watch?v=5KdvPp1_JeI' frameborder='0' allowFullScreen></iframe>"
  }}
  document.write(obj.video.value);