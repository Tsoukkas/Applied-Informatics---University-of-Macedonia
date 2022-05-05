#include <string.h>
#include <stdio.h>

void read(FILE *infile,int *min,int *max){
int x,nscan;
while(1){
nscan=fscanf(infile,"%d",&x);
if(nscan==EOF){
break; }
if(x>*max){
*max=x;}
 if(x<*min){
*min=x;}
}}




int main(){
int min=777;
int max=0;
FILE *infile;
char name[30];
printf("Dwse onoma arxiou:");
gets(name);
infile=fopen("name","r");
read(infile,&min,&max);
printf("To max einai o arithmos %d",max);
printf("To min einai o arithmos %d",min);
fclose(infile);
return 0;
}
