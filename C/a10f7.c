#include<stdio.h>
#include<string.h>
#include"genlib.h"
#include"simpio.h"
#include<ctype.h>
char RegularPluralForm(char word[]);
int main(){
char word[21];
char plithintikos[25];
plithintikos[25]=RegularPluralForm(word);
return 0;}
bool IsVowel(char ch)
{
char lowerCh;
lowerCh = tolower(ch);
 switch( lowerCh )
{
case 'a':
    return (TRUE); break;
case 'e':
     return (TRUE); break;

case 'i':
    return (TRUE); break;
case 'o':
    return (TRUE); break;
case 'u':
 return (TRUE); break;

default:

return FALSE;
}
}

char RegularPluralForm(char word[]){
    int len;
len=strlen(word)-1;
if((word[len]=='s' ||word[len]=='x') || (word[len]=='h' && word[len-1]=='c') || (word[len]=='h' && word[len]=='s')){
word[len+1]='e';
word[len+2]='s';
word[len+3]='\0';
}
else if(IsVowel(word[len-1])){
word[len-2]='i';
word[len-1]='e';
word[len]='s';
word[len+1]='\0';
}
else{
word[len+1]='s';
word[len+2]='\0';
}
return word[25]; }
