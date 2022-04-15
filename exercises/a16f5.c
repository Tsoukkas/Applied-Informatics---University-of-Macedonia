#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
#include<stdlib.h>
void printArr(int table[50]){
for(int i=1;i<=50;i++){
printf(" %d",table[i]);}
}

int checkTable(int table[50],int a,int table1[50]){
int total=0;
for(int i=1;i<=50;i++){
if(table[i]==a){
table1[total]=i-1;
total+=1;
}}
return total;}

int main(){
int a[50],num;
int thesis[50];
for(int i=1;i<=50;i++){
a[i]=rand()%10;}
printArr(a);
printf("\n---------------\n");
printf("Dwse arithmo apo to 0 ews to 9:");
num=GetInteger();
printf("O Arithmos %d emfanizetai %d fores\n",num,checkTable(a,num,thesis));
printf("Stis Thesis:\n");
for(int i=0;i<checkTable(a,num,thesis);i++){
printf(" %d",thesis[i]);
}
printf("\n-----------------");
return 0;
}
