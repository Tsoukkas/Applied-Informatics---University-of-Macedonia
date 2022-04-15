#include<stdio.h>
void findHighest(int n,int m,int a[n][m]);
void findthesmallest(int n,int m,int a[n][m]);
int main(){
int m,n;
int a[2][3];
printf("Dwse arithmo gramwn:");
scanf("%d",&n);
printf("Dwse arithmo stilwn:");
scanf("%d",&m);
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("Dwse stixio:");
scanf("%d",&a[i][j]);
}}
findHighest(n,m,a);
findthesmallest(n,m,a);
return 0;
}

void findHighest(int n,int m,int a[n][m])
{
     for (int i = 0; i < n; i++)
     {
         int max = a[i][0];
         for (int j = 1; j < m; j++)
         {
             if (a[i][j] > max)
             {
                max = a[i][j];
             }
         }
        printf("The max of %d row is %d\n",i+1,max);
     }
}
void findthesmallest(int n,int m,int a[n][m]){
    for(int j=0;j<m;j++){
        int min=a[0][j];
        for(int i=0;i<n;i++){
            if(a[i][j]<min){
                min=a[i][j];
            }
        }
        printf("The smallest of the %d column is %d\n",j+1,min);
    } }
