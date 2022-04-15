#include<stdio.h>
#include<string.h>
void founds1(FILE *infile,FILE *outfile){
int nscan,i;
long num[20];
while(1){
nscan=fscanf(infile,"%ld",num);
if(feof(infile)){
break;
}
else{
for(i=0;i<=20;i++){
if(num[i]==0){
num[i]=1;
}
else{
num[i]=0;
}
}
fprintf(outfile,"%ld",num);
}}}
int main(){
FILE *infile,*outfile;
char in[20],out[20];
printf("Dwse arxio eisodou:");
gets(in);
printf("Dwse arxio eksodou:");
gets(out);
infile=fopen("in","r");
outfile=fopen("out","w");
founds1(infile,outfile);
fclose(infile);
fclose(outfile);
return 0;
}
