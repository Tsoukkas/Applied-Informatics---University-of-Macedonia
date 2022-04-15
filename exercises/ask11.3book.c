#include<stdio.h>
#include<string.h>
int main(){
char *p;
int i=0,count=0;
p="αρνακι ασπρο και παχυ";
while((p[i]) != '\0'){
if(p[i]=='σ'){
count++;
}i++;
}
printf("to grama s emfanizete %d fores",count);
return 0;
}
