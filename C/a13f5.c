#include<stdio.h>
#include<stdlib.h>
#include"simpio.h"
#include"genlib.h"
void populate_data(int rows,int columns,int table[rows][columns]){
for(int i=0;i<rows;i++){
for(int j=0;j<columns;j++){
table[i][j]=rand() % 100;}}}

void print_array(int rows,int columns,int table[rows][columns]){
for(int i=0;i<rows;i++){
        printf("\n");
for(int j=0;j<columns;j++){
printf("%d\t",table[i][j]);
}}}

void change_array(int rows,int columns,int table[rows][columns],int max){
int x;
for(int i=0;i<rows;i++){
max=table[i][0];
x=0;
for(int j=0;j<columns;j++){
if(table[i][j]>max){
max=table[i][j];
 x=j; } }
for (int j=0;j<x;j++){
table[i][j]=max; }} }

int main(){
int grames,stiles,a[10][10];
int max;
printf("Dwse ton arithmo twn grammwn:");
grames=GetInteger();
printf("Dwse ton arithmo twn sthlwn:");
stiles=GetInteger();
printf("ARXIKOS PINAKAS\n");
populate_data(grames,stiles,a);
print_array(grames,stiles,a);
change_array(grames,stiles,a,max);
printf("\nALLAGMENOS PINAKAS\n");
print_array(grames,stiles,a);
return 0;
}

