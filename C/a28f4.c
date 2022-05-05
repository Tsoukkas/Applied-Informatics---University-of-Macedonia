#include<stdio.h>
#include<math.h>
#include"simpio.h"
#include"genlib.h"
int get_code();
double discount_percentage(int code);
int product_points(int code,double fprice);
int main(){
int code,points;
double fprice,price,discount,total,discountsum;
total=discountsum=0;
points=0;
while(code=get_code()){
printf("Dwse thn timi:");
price=GetReal();
discount=discount_percentage(code)*price;
discountsum+=discount;
fprice=price-discount;
total+=fprice;
points+=product_points(code,fprice);
}
printf("________________________________\n");
printf("Teliko synolo: %.2f Euro\n",total);
printf("Ekptosi: %.2f Euro\n",discountsum);
printf("Pontoi: %d\n",points);
return 0;
}
int get_code(){
int code;
while(TRUE){
printf("Dwse kodiko:");
code=GetInteger();
if(code>=0 && code<=2000){
return code;}
else{
printf("Lathos kodikos (0-2000)");
}}
}
double discount_percentage(int code){
double sale;
if(code<=300){
sale=0.05;}
if(code>300 && code<=500){
sale=0.10;}
if(code>500 && code<=1000){
sale=0.15;}
else{
sale=0.20;}
return sale;}
int product_points(int code,double fprice){
int points=1;
if(code>=1000 && code<=1500){
points+=ceil(fprice/5);
}
return points;
}
