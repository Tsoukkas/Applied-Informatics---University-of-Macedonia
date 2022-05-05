#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
void Read_Array(long M,long N,long a[M][N]){
int i=1,j=1;
for(i=1;i<=M;i++){
for(j=1;j<=N;j++){
a[i][j]=GetLong();
}}}


void Find_Min_of_Rows(long M,long N,long a[M][N], int min[M]){
int i,j;
long min1=6666;
for(i=1;i<M;i++)
{
min1=a[i][1];
for(j=1;j<N;j++) {
 if (a[i][j]<min1){
    min1=a[i][j];
    min[i]=min1;
} min1=777;
}
} }



void print(long M,long N,int min[M]){
int i,j;
for(i=1;i<M;i++){
for(j=1;j<N;j++){
printf("%d\n",min[i]);
}} }


int main(){
long M,N;
printf("Dwse thn timh tou m:");
M=GetLong();
printf("Dwse thn timh tou n:");
N=GetLong();
long a[M][N];
int min[M];
Read_Array(M,N,a);
Find_Min_of_Rows(M,N,a,min);
print(M,N,min);
return 0;
}
