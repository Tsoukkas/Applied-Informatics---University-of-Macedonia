#include<stdio.h>
#include<math.h>
#include"simpio.h"
int main(){
double a[5],b[4];
for(int i=0;i<5;i++){
printf("Enter number (%d):",i);
a[i]=GetReal();
}
for(int i=0;i<5;i++){
printf("%.2lf ",a[i]);
}
printf("\n");
for(int i=1;i<5;i++){
b[i]=a[i+1]-a[i];
fabs(b[i]);
}
for(int i=1;i<5;i++){
printf("%.2lf ",b[i]);
}
return 0;
}
