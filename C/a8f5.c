#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
#define m 2
#define n 3
void Read_Data(int a[m][n]){
int i,j;
for(i=1;i<=m;i++){
for(j=1;j<=n;j++){
a[i][j]=GetInteger();
}}}

void Write(int a[m][n]){
int i=1,j=1;
for(i=1;i<=m;i++){
for(j=1;j<=n;j++){
printf("%d ",a[i][j]);
}
} }

int main(){
int a[m][n];
Read_Data(a);
Write(a);
return 0;
}
