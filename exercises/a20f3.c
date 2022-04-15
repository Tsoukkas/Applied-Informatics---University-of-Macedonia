#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main(){
int age=-69;
int max=0;
int min=400;
do{
     printf("Dwse ilikia:");
    age=GetInteger();
    if(age>max){
            max=age;}
   if(age!=-1 && age<min){
        min=age;
}
}while(age!=-1);
printf("i megaliteri ilikia ine:%d\n",max);
printf("i mikroteri ilikia ine:%d\n",min);
return 0;
}

