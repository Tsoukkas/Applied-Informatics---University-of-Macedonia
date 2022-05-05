#include<stdio.h>
#include<string.h>
void readfile(FILE *infile);
int main(){
FILE *infile;
char name[20];
printf("Dwse onoma arxiou gia anagnosi:");
gets(name);
readfile(infile);
fclose(infile);
return 0;
}

void readfile(FILE *infile){
int nscan,num;
char name1[20],name2[20];
FILE *out1,*out2;
printf("Dwse onoma epitixontwn tipou .ep:");
gets(name1);
out1=fopen("name1","w");
out2=fopen("name2","w");
printf("Dwse onoma apotixontwn tipou .ap:");
gets(name2);
char name[20];
while(1){
nscan=fscanf(infile,"%20[^" "],%d",name,num);
if(nscan==EOF){
break;
}
if(num>=5){
fprintf(out1,"%s",name);
}
else{
fprintf(out2,"%s",name);
}
fclose(out1);
fclose(out2);
} }
