#include<stdio.h>
#include<string.h>
int main(){
char word[20],word1[20],common[20];
int i=0;
printf("Please insert two word to find the common characters.\n");
printf("Word 1:");
gets(word);
printf("Word 2:");
gets(word1);
while(1){
        if(word[i]=='\0' || word1[i]=='\0'){
            break;
        }
    if(word[i]==word1[i]){
       common[i]=word[i];
    }
i++;
}
printf("Common Characters of %s in %s:%s",word,word1,common);
return 0;
}
