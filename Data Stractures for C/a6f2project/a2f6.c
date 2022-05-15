#include <stdio.h>
#include <stdlib.h>
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
StackElementType GetTopElement�(StackType AStack);
StackElementType GetTopElementB(StackType AStack);

int main(){
StackType AStack;
StackElementType a,Item,AnItem;
CreateStack(&AStack);
for(int i=0;i<=1000;i++){
    if(i%2 == 1 ){
        Push(&AStack,i);
    }
}
Item=GetTopElement�(AStack);
AnItem=GetTopElementB(AStack);
if(Item==AnItem){
    printf("DULEFKUN SOSTA");
}
else{
    printf("DULEFKUN LATHOS");
}
return 0;
}


StackElementType GetTopElement� (StackType AStack){
    StackElementType Item;
    if(!(EmptyStack(AStack))){
    Pop(&AStack,&Item);
    Push(&AStack,Item); }
    else{
        printf("There is no any Items in the Stack\n");
    }
return Item;
}

StackElementType GetTopElementB (StackType AStack){
    StackElementType AnItem;
    if(!(EmptyStack(AStack))){
    for(int i=0;i<=1000;i++){
    if(i==999){
    Pop(&AStack,&Item);
    Push(&AStack,Item);} } }
    else{
        printf("There is no any Items in the Stack\n");
    }
return Item;
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

