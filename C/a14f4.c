#include<stdio.h>
#include<math.h>
#include"simpio.h"
#include"genlib.h"
int max(int a,int b){
if(a>b){
return a;
}
else{
return b;}
}
int gr(int a,int b,int c){
if(max(a,b)>c){
    return max(a,b);
}
else{
    return c;
}
}
int main(){
int a,b,c;
float y,x;
printf("Dwse a:");
a=GetInteger();
printf("Dwse b:");
b=GetInteger();
printf("Dwse c:");
c=GetInteger();
x=((2*max(a,b))+(3*gr(a,b,c)));
y=x/4;
printf("y=%.2f",y);
return 0;
}
