// FILENAME StackADT.h
                    /* ��������� ������� �� ������ *
              *�� �������� ��� ������� ����� ����� int */
#include<stdio.h>
#include<stdlib.h>
#define StackLimit 50   // �� ���� �������� ��� �������, ���������� ��� �� 50


typedef int StackElementType;   // � ����� ��� ���������  ��� �������
                                //���������� ����� int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

int main(){
int TotalProfit;
StackType s1,s2,s3,s4;
CreateStack(&s1);
CreateStack(&s2);
CreateStack(&s3);
CreateStack(&s4);
int a,b,c,g,e,f,o;
int i=0,x=0;
StackElementType Item,AnItem;
while(i<6){
printf("Enter the orderType,volume,price: ");
scanf("%d",&a);
printf(",");
if(a<0){ break ;
}
scanf("%d",&b);
printf(",");
if(b<0){ break ;
}
scanf("%d",&c);
printf(",");
if(c<0){ break ;
}
if(a==0){
    Push(&s1,b);   //posotita
    Push(&s2,c);   //timi
    x++;
}
if(a==1){
    while(x != 0){
        Pop(&s1,&Item);
        Pop(&s2,&AnItem);
    }
}
while(1){
    if(!EmptyStack(s3)){
        Pop(&s1,&g);
        Pop(&s2,&e);
        Pop(&s1,&f);
        Pop(&s2,&o);
    }
}
int apotelesma;
apotelesma=Item*o-(g*e+f*AnItem);
TotalProfit+=apotelesma;
printf("Trasaction Profit: %d",apotelesma);

i++;
}
printf(" Total Profit :%d ",TotalProfit);
return 0;
}


void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}


