#include<stdio.h>
#include<string.h>
typedef struct{
char apok[30];
}st;
int main(){
FILE *infile;
st a[5];
char name[30];
char cr[30];
char termch;
int x=0,nscan;
printf("Dwse onoma arxiou gia apokriptografisi:");
gets(name);
infile=fopen("name","r");
if(infile==NULL){
printf("This file doesn't exists");
}
else{
while(1){
nscan=fscanf(infile,"%30s,%c",a[x].apok,&termch);
if(nscan==EOF){
break;
}
x++;
} }
for(int i=0;i<x;i++){
for(int j=0;j<30;j++){
a[i].apok[j]=a[i].apok[j-1];
}}
for(int i=0;i<x;i++){
printf("%s\n",a[i].apok);
}
fclose(infile);
return 0;
}
