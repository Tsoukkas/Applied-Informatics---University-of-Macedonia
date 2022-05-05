#include<stdio.h>
#include<string.h>
int main(){
char ptr[20],arxi[20],ch;
int c=0,i=0;
ptr[20]="มออมอมำ";
arxi[20]=ptr[20];
while(ptr[i]='\0'){
c++;
i++;
}
while(ptr[20]>=arxi[20]){
printf("%c",*ptr);
ptr--;
}
return 0;
}
