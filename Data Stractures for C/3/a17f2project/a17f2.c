#include<stdlib.h>
#include<stdio.h>
#include<string.h>
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
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
StackType CopyStack(StackType *s1){
StackElementType x;
StackType s3,tmp;
CreateStack(&s3);
CreateStack(&tmp);
while(!EmptyStack(*s1)){
    Pop(&(*s1),&x);
    Push(&s3,x);
    Push(&tmp,x);
}
while(!EmptyStack(tmp)){
    Pop(&tmp,&x);
    Push(&(*s1),x);
}
 return s3;
}

int main(){
StackType s1,s2;
CreateStack(&s1);
CreateStack(&s2);
for(int i=0;i<20;i++){
   Push(&s1,i);
}
printf("Stack s1");
TraverseStack(s1);
s2=CopyStack(&s1);   //antigrafi tin stiva 1 stin stiva 2 xoris omos na alazi i stiva 1
printf("After copying s1 to s2");
printf("Stack s1");
TraverseStack(s1);
printf("Stack s2");
TraverseStack(s1);
return 0;
}
