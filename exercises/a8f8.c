#include<stdio.h>
#include "simpio.h"
#include "genlib.h"
typedef struct{
int width;
int  height;
int  depth;
int area;
int  volume;
}box;

box diastasis(box box1){
printf("Dose to mikos tou koutiou se cm:");
scanf("%d",&box1.width);
printf("Dose to ypsos tou koutiou se cm:");
scanf("%d",&box1.height);
printf("Dose to vathos tou koutiou se cm:");
scanf("%d",&box1.depth);
return box1;
}


void emvadon(box *box1){
(*box1).area=2*(((*box1).width*(*box1).depth)+((*box1).width*(*box1).height)+((*box1).depth*(*box1).height));
}


void ogkos(box *box1){
(*box1).volume=(*box1).width*(*box1).height * (*box1).depth;
}

int main(){
box box1;

box1=diastasis(box1);
emvadon(&box1);
ogkos(&box1);

printf("To emvadon tou koutiou einai %d cm2\n",box1.area);

printf("O ogos tou koutiou einai %d cm3\n",box1.volume);

return 0;
}
