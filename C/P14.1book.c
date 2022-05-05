#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>
void write(FILE *outfile){
int i;
char lexi[20];
while (1) {
printf("Dwse lexi gia egrafi:");
scanf("%s",lexi[20]);
if(lexi==" "){
break;}
else{
fprintf(outfile,"%s",lexi);
}}
}
int main(){
char name[20];
FILE *outfile;
printf("Dwse arxio gia egrafi:");
scanf("%s",name[20]);
outfile=fopen("name[20]","w");
write(outfile);
fclose(outfile);
return 0;
}
