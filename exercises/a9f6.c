#include<stdio.h>
#define SALESMEN 4
#define PRODUCTS 5
void calculatesales(int S,int P,int sales[S][P],int prices[P],int salesperson[S]){

for(int i=0;i<S;i++){
salesperson[i]=0;
for(int j=0;j<P;j++){
salesperson[i] += sales[i][j]*prices[j];}}}

void calculateProductSales(int P,int S,int sales[S][P],int productSales[]){
    int i,j;
for(i=0;i<P;i++){
    productSales[i]=0;
    for( j=0;j<S;j++){
        productSales[i]+=sales[j][i];
    }}
}

void maxArray(int size,int table[],int *max,int *pos){
*max=table[0];
*pos=0;
for(int i=1;i<size;i++){
    if(*max<table[i]){
    *max=table[i];
    *pos=i; } }
}
void printArray(int size,int table[]){
int i;
for(i=0;i<size;i++){
printf("   %d   %d\n",i,table[i]);
}}
int main(){
int income,items;
int maxSalesMan,MaxProduct;
int salesperson[SALESMEN];
int productSales[PRODUCTS];
int prices[PRODUCTS]={250,150,320,210,920};
int sales[SALESMEN][PRODUCTS]={10,4,5,6,7,
                               7,0,12,1,3,
                               4,19,5,0,8,
                               3,2,1,5,6 };

calculatesales(SALESMEN,PRODUCTS,sales,prices,salesperson);
calculateProductSales(PRODUCTS,SALESMEN,sales,productSales);
maxArray(SALESMEN,salesperson,&income,&maxSalesMan);
maxArray(PRODUCTS,productSales,&items,&MaxProduct);
printf("SalesMan-Sales\n");

printArray(SALESMEN, salesperson);
printf("Best Sales was %d with %d sales\n",maxSalesMan,income);

printf("Product-Items \n");
printArray(PRODUCTS,productSales);
printf("Best Product was %d with %d items\n",MaxProduct,items);
return 0;
}
