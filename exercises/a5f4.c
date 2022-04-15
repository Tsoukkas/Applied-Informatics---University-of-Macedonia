#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
int  Sum_Cupe(int num);
bool IsArmStrong(int num);
int Sum_Cupe(int num){
 int athroisma,x,y,w;
 x=num/100;
 y=(num%100)/10;
 w=num%10;
 athroisma=(x*x*x)+(y*y*y)+(w*w*w);
return athroisma;
}
int main(){
int i;
for( i=1;i<=999;i++){
        if(IsArmStrong(i)){
         printf("%d\n",i); }

}


}
bool IsArmStrong(int num){
 return (num==(Sum_Cupe(num)));
}

