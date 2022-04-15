#include<stdio.h>
#include"simpio.h"
#include"genlib.h"
bool validtime(int hours,int min,int sec);
int main(){
int hours,min,sec;
printf("Dwse tis ores:");
hours=GetInteger();
printf("Dwse ta lepta:");
min=GetInteger();
printf("Dwse ta defterolepta:");
sec=GetInteger();
if(validtime(hours,min,sec=='TRUE')){
printf("WRA EGKYRH");}
else{
printf("WRA MH EGKIRH");
}
return 0;
}
bool validtime(int hours,int min,int sec){

 if
    ((hours>=0) && (hours<=23) && (min>=0) && (min<=59) && (sec>=0) && (sec<=59)){
        return TRUE;
}
else{
    return FALSE;
}

  }
