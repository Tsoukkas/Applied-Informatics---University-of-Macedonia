#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define StackLimit 50   // �� ���� �������� ��� �������, ���������� ��� �� 50


typedef char StackElementType;   // � ����� ��� ���������  ��� �������
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
StackType s1,s2,s3,s4;
StackElementType ch;
CreateStack(&s1);
CreateStack(&s2);
CreateStack(&s3);
CreateStack(&s4);
 ///1. �������� ��� ���������� �P�, �A�, �S�, �C�, �A�, �L� ��� ������ Stack1:
  Push(&s1,'P');
  Push(&s1,'A');
  Push(&s1,'S');
  Push(&s1,'C');
  Push(&s1,'A');
  Push(&s1,'L');
printf("Stack 1\n");
TraverseStack(s1);
printf("\n");
printf("Stack 2\n");
int i=1;
while(i<=6){
    Pop(&s1,&ch);
    Push(&s2,ch);
i++;
}
s1=s2;
i=1;
while(i<=6){
    Pop(&s2,&ch);
    Push(&s3,ch);
i++;
}
TraverseStack(s1);
printf("\n");
printf("Stack 3\n");
TraverseStack(s3);
printf("\n");
printf("Stack 1\n");
TraverseStack(s1);
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
    for (i=0;i<=Stack.Top;i++) {
        printf(" %c, ",Stack.Element[i]);
    }
    printf("\n");
}
