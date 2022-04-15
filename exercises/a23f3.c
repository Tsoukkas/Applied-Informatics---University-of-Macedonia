#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int main (){
int num;
printf("Enter Number:");
num=GetInteger();
if(num%2==0){
for(int i=0;i<num;i+=2){
printf("%d_",i);
}}
else
{
for(int i=1;i<num;i+=2){
printf("%d_",i);
}}
printf("%d",num);
return 0;
}
