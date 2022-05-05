#include<stdio.h>
#include<stdlib.h>
void find_the_max(int *max1,int *max2,int e[],int st[],int *index1,int *index2){
(*max1)=e[0];
(*index1)=0;
for(int i=0;i<8;i++){
if(e[i]>(*max1)){
(*max1)=e[i];
(*index1)=i;
}}
(*max2)=st[0];
(*index2)=0;
for(int j=0;j<5;j++){
if(st[j]>(*max2)){
(*max2)=st[j];
(*index2)=j;
}}}
int main(){
int e[8],st[5];
int max1,max2,index1,index2;
for(int i=0;i<8;i++){
e[i]=rand() %20;
}
for(int j=0;j<5;j++){
st[j]=rand()% 20;
}
find_the_max(&max1,&max2,e,st,&index1,&index2);
printf("o megaliteros vathmos tis e taxis ine %d kai ton exi o %d mathitis\n",max1,index1);
printf("o megaliteros vathmos tis st taxis ine %d kai ton exi o %d mathitis",max2,index2);
return 0;
}
