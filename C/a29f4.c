#include<stdio.h>
#include<math.h>
#include"simpio.h"
#include"genlib.h"
int gcd(int a,int b){
if(b==0){
return a;
} else {
return gcd(b,a%b); } }
bool coprime (int a,int b){
return (gcd(a,b)==1);
}

int phi(int x){
int total=0;
for(int i=1;i<=x;i++){
if(coprime(i,x)){
total+=1;    }
else { continue ;}

}return total;}

int main(){
int x;
printf("Enter x:");
x=GetInteger();
for(int i=1;i<=x;i++){
printf("phi(%d) = %d\n",i,phi(i));
}
return 0;
}
