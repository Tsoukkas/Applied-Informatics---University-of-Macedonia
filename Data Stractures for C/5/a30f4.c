#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10
#define NilValue -1
#define StackLimit 100

typedef struct{
int am;
float grade;
} ListElementType;


typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void TraverseStack(StackType Stack);
void menu(int *choice);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);


int main()
{
    int Apos;
    ListElementType AnItem;
    ListPointer AList,FreePtr,PredPtr,CurrPtr;
    NodeType Node[100];
    int i;
    StackType s;
    float min;
    int am;

   int choice;
   char ch;

//a
InitializeStoragePool(Node,&FreePtr);
//b
CreateList(&AList);
//c
printf("---------------Question C--------------------\n");
printf("--------------Storage pool-------------------\n");
printAll(AList,FreePtr,Node);
//d
printf("---------------Question D--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(AList,Node);
//e
printf("---------------Question E--------------------\n");
PredPtr=NilValue;
for(i=0;i<5;i++){
   printf("DWSE AM GIA EISAGWGH STH LISTA: ");
   scanf("%d",&AnItem.am);
   printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
   scanf("%f",&AnItem.grade);
Insert(&AList,Node,&FreePtr,PredPtr,AnItem);
}

//f
printf("---------------Question F--------------------\n");
printf("--------------Storage pool-------------------\n");
printAll(AList,FreePtr,Node);
//g
printf("---------------Question G--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(AList,Node);
//h
printf("---------------Question H--------------------\n");
if(EmptyList(AList)){
        printf("Empty List");
}
else printf("Not an Empty List");
//i
printf("\n---------------Question I--------------------\n");
if(FullList(AList)){
        printf("Full List");
}
else printf("Not an Full List");

//j
printf("\n---------------Question J--------------------\n");
min=FindMins(AList,Node,&s);
printf("Min grade: %.1f\n",min);
printf("AM with min grade are: ");

while(!EmptyStack(s)){

    Pop(&s,&s.Element[s.Top]);
     printf("%d",&s.Element[s.Top]);

}

//k
printf("\n---------------Question K--------------------\n\n");
TraverseStack(s);
//l
printf("---------------Question L--------------------\n");
printf("--------------Storage pool-------------------\n");
printAll(AList,FreePtr,Node);
//m
printf("---------------Question M--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(AList,Node);



	return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)

{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am=-1;
         Node[i].Data.grade=-1;
}
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=-1;
    Node[NumberOfNodes-1].Data.grade=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)

{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)

{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)

{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])

{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)

{
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1;
  Node[P].Data.grade = -1;
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)

{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)

{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[]){
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:<%d,%.1f->%d) ",CurrPtr,Node[CurrPtr].Data.am,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

   void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}


void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)

{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)

{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f->%d) ",i,Node[i].Data.am,Node[i].Data.grade, Node[i].Next);
    printf("\n");
}


float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack){
ListPointer CurrPtr;
float min;
StackElementType Item;

CreateStack(Stack);
if(!EmptyList(List)){
    CurrPtr=List;
    min=Node[CurrPtr].Data.grade;
while (!CurrPtr == NilValue){
       if(Node[CurrPtr].Data.grade<=min){
        if(Node[CurrPtr].Data.grade<min){
        while(!EmptyStack(*Stack)){
        Pop(Stack,&Item);
       }
       min=Node[CurrPtr].Data.grade;
       }
       Push(Stack,&Node[CurrPtr].Data.am);
       }
        CurrPtr=Node[CurrPtr].Next;
       }
}
else printf("Empty List...");

return min;
}

