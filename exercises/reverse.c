#include<stdio.h>
#include<string.h>
void reverse(char lexi[6]){
char rev[6];
int end;
int i=0;
int len=strlen(lexi);
len--;
end=len;
while(end>=0){
rev[i]=lexi[end];
i++;
end--;
}
rev[len+1]='\0';
printf("%s",rev);
}
int main(){
char lexi[10];
printf("Dwse mas tin lexi:");
gets(lexi);
reverse(lexi);
return 0;
}
