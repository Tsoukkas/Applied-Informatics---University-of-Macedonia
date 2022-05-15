// Filename ListADT.h
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef int ListElementType;           /* � ����� ��� ��������� ��� ������������ ������
                                        ���������� ����� int */
typedef struct ListNode *ListPointer;   //� ����� ��� ������� ��� ���� �������
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void concat_list(ListPointer AList,ListPointer BList,ListPointer *FinalList,int *x);
void tomi(ListPointer AList,ListPointer BList,ListPointer *Tomi);
int main()
{
    int n,c;
    ListPointer AList,BList,FinalList,Tomi;
    CreateList(&AList);
    CreateList(&BList);
    CreateList(&FinalList);
    CreateList(&Tomi);
    printf("Dose to stixio p thes na valis stin lista:");
    scanf("%d",&n);
    LinkedInsert(&AList,n,NULL);   //a
    LinkedDelete(&AList,NULL);

    BList=AList; //b //antigrafo tis protis listas
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1:");
    scanf("%d,&c");
    LinkedInsert(&AList,c,NULL);
    }

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2:");
    scanf("%d,&c");
    LinkedInsert(&BList,c,NULL);
    }
    int x=0;
   printf("LISTA 1:\n");
LinkedTraverse(AList);
printf("\nLISTA 2:\n");
LinkedTraverse(BList);          //dini posa kai ta isagi se kathe lista ta stoixeia
printf("\nSYNENWMEN� LISTA:\n");
concat_list(AList,BList,&FinalList,&x);

LinkedTraverse(FinalList);
//c


while(!EmptyList(AList)){
    LinkedDelete(&AList,NULL);
}
while(!EmptyList(BList)){
    LinkedDelete(&BList,NULL);
}
printf("\nDose to n:\n");
scanf("%d",&n);
if(n>x){
    printf("ERROR\n");
}
else{
    LinkedDelete(&FinalList,n-1);
}
//d

LinkedDelete(&FinalList,1);
//e

for(int i=0;i<=2;i++){
    LinkedInsert(&AList,i,NULL);
}
for(int i=3;i<=5;i++){
    LinkedInsert(&BList,i,NULL);
}
printf("1 LISTA:\n");
LinkedTraverse(&AList);
printf("2 LISTA:\n");
LinkedTraverse(&BList);

tomi(AList,BList,&Tomi);  //i
LinkedTraverse(Tomi);


LinkedDelete(&AList,2);
LinkedDelete(&BList,2);  //h







}

void tomi(ListPointer AList,ListPointer BList,ListPointer *Tomi){
ListPointer c1,c2;
c1=AList;
c2=BList;
for(int i=0;i<=2;i++){
        if(c1->Data=c2->Data){
     LinkedInsert(Tomi,c1->Data,NULL);
     }
    c1=c1->Next;
    c2=c2->Next;
}
}
void concat_list(ListPointer AList,ListPointer BList,ListPointer *FinalList,int *x){
ListPointer CurrPtr;
CurrPtr=AList;
while(CurrPtr != NULL){
    LinkedInsert(&(*FinalList),CurrPtr->Data,NULL);
    CurrPtr=CurrPtr->Next;
    *x++;

}
CurrPtr=BList;
while(CurrPtr != NULL){
    LinkedInsert(&(*FinalList),CurrPtr->Data,NULL);
    CurrPtr=CurrPtr->Next;
    *x++;
}
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
  ����������:  ��� �������� ������ List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� �� � ����������� ����� ����� ����.
  ����������: True �� � ����� ����� ���� ��� false �����������
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����,
                ��� �������� ��������� Item ��� ���� ������ PredPtr.
   ����������: ������� ���� �����, ��� �������� �� Item, ���� ����������� �����
                ���� ��� ��� ����� ��� �������������� ��� ��� PredPtr
                � ���� ����  ��� ������������ ������,
                �� � PredPtr ����� ���������(NULL).
  ����������:  ��� ������������� ����������� ����� �� ��� ����� ����� ���
                �� �������������� ��� ��� List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� ����� ���
                 ��� ���� ������ PredPtr.
   ����������: ��������� ��� �� ����������� ����� ��� ����� ��� ����
                ��� ����������� ��� ����� ���� ����� ������� � PredPtr
                � ��������� ��� ����� �����, �� � PredPtr ����� ���������,
                ����� ��� �� � ����� ����� ����.
   ����������: ��� ������������� ����������� ����� �� ��� ����� �����
                �� �������������� ��� ��� List.
   ������:     ��� ������ ����� ������ �� � ����������� ����� ���� ���� .
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
   ����������: ��������� �� ����������� ����� ���
                ������������� ���� �������� ������� ��� ����.
   ����������: ��������� ��� �� ����� ��� ������������.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;


         while ( CurrPtr!=NULL )
        {
             printf(" %d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� ��� �������� ��������� ���� �� ������������ �����������
              ����� ��� ���� ����� ��� �� �������� �� �������� Item.
  ����������: �� � ��������� ����� �������� � Found ����� true, � CurrPtr �������
                ���� ����� ��� �������� �� Item ��� � PredPtr ���� ����������� ���
                � ����� nil �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
*/
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* �������:    ��� �������� Item ��� ��� ������������ ����������� �����,
                ��� �������� �������� ��������� �� ������� ������� ��� ���� �����
                � ������� List ������� ���� �����  �����.
   ����������: ������� �������� ��������� ��� ������������ ������������� ������
                ��� ��� ����� ����� ��� �������� �� �������� Item � ��� ��� ����
                ��� �� ������� ��� ��� ����� ��� �� �������� �� �������� Item.
   ����������: �� � ��������� ����� �������� � Found ����� true,
                � CurrPtr ������� ���� ����� ��� �������� �� Item ���
                � PredPtr ���� ����������� ��� � ����� nil �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
*/
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}


