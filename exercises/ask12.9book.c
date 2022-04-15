#include<stdio.h>
void read(int a[][3]){
int i,j;
for(i=0;i<=49;i++){
for(j=0;j<=2;j++){
scanf("%d",a[i][j]);
}}}
int main(){
int x,c;
int a[50][3];
read(a);
double mo[50];
for(int i=0;i<=49;i++){
for(int j=0;j<=2;j++){
mo[i]=a[i][j]+a[i][j+1]+a[i][j+2];
}}
for(int i=0;i<=49;i++){
if(mo[i]<9.5){
x++;
}
else if(mo[i]>18.5){
c++; }}
printf("apetixan %d mathites",x);
printf("aristefsan %d mathites",c);
return 0;
}
