#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
int kivotia;
int date;
} StackElementType;           /*� ����� ��� ��������� ��� �������
                                        ���������� ����� int */
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);
StackPointer stack_check(StackPointer A,StackPointer B,StackPointer C);

int main(){
StackPointer A,B,C;
CreateStack(&A);
CreateStack(&B);
CreateStack(&C);
printf("Plithos fortiwn:");
int n;
StackElementType x;
scanf("%d",&n);
for(int i=1;i<=n;i++){
    printf("Arithmos kivwtiwn gia to %do fortio:",i);
    scanf("%d",x.kivotia);
    printf("Imeromhnia liksis gia to %do fortio:",i);
    scanf("%d",x.date);
    Push((stack_check(A,B,C)),x);
}
printf("**********WAREHOUSE 1**************\n");
TraverseStack(A);
printf("**********WAREHOUSE 2**************\n");
TraverseStack(B);
printf("**********WAREHOUSE 3**************\n");
TraverseStack(C);
return 0;
}
StackPointer stack_check (StackPointer A,StackPointer B,StackPointer C){
if(A->Next > B->Next && A->Next > C->Next){
    return A;
}
else if(B->Next>A->Next && B->Next>C->Next){
return B;
}
else if(C->Next>A->Next && C->Next>B->Next){
    return C;
}
else if(A->Next==B->Next==C->Next){
    return A;
}
else if(B->Next==C->Next){
    return B;
}
else if(A->Next==C->Next){
    return A;
}
else if(B->Next=A->Next){
    return A;
}
}

void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

