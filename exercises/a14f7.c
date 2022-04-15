#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char lexi[5],lexi1[5];
printf("Word to shuffle :");
gets(lexi);
for(int i=0;i<5;i++){
lexi1[rand()%5]=lexi[i];
}
printf("Initial Word: %s, New Word: %s",lexi,lexi1);
return 0;
}

