#include<stdio.h>
#include"simpio.h"
#include<math.h>
#include"genlib.h"
int main(){
double matrix[5];
double d[5];
for(int i=0;i<5;i++){
printf("Enter number (%d):",i);
matrix[i]=GetReal(); }
for(int i=1;i<5;i++){
d[i]=fabs((matrix[i])-(matrix[i-1]));
}
for(int i=0;i<5;i++){
printf(" %.2lf",matrix[i]);
}
printf("\n");
for(int i=0;i<4;i++){
printf(" %.2lf",d[i+1]);
}

return 0;

}
