#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define StackLimit 200   // �� ���� �������� ��� �������, ���������� ��� �� 50


typedef char StackElementType;   // � ����� ��� ���������  ��� �������
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

int main(){
StackType s;
CreateStack(&s);   //dimiurgi stiva
boolean valid;
int flag;
char ch;
char item;

flag=0;
valid=TRUE;

printf("Enter a string\n");
scanf("%c",&ch);getchar();  //dini ton proto xaraktira
if(ch=='#'){
return 0;
}  // an ine o # telioni to programa
while(ch != '#' && valid==TRUE){
if(flag==0){    //dld an den edose C akoma
if(ch=='C'){
flag=1;
scanf("%c",&ch);getchar();            //an to edose kai pai ston epomeno xaraktira
}
else{
Push(&s,ch);
scanf("%c",&ch);getchar();
} }
else{
if(!EmptyStack(s)){
   Pop(&s,&item);
     if(item!=ch){
    valid=FALSE;}
     else{
  scanf("%c",&ch);getchar();}
}
else{
   valid=FALSE;
}} }
if(valid==TRUE && EmptyStack(s)){
printf("TRUE");
}
else{
printf("FALSE");
}
return 0;
}
