#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10    /*���� �������� ��� ������������ ������,
                            ���������� ������ ��� �� 50*/
#define NilValue -1          // ������ �������� ���� ������� �� ����� ��� ����.������

typedef int ListElementType; /*����� ��������� ��� �� �������� ��� ������������ ������,
                                ���������� ���������� � ����� int */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* �������:   ��� ������ Node ��� ��� ������ FreePtr ��� ������� ����
                ����� ��������� �����.
  ����������: ����������� ��� ������ Node �� ����������� ����� ���������� ������
                ���� ���������� �������� ��� ������,
                ��� ����������� ��� ������ FreePtr .
  ����������: ��� ������������� ������ Node ��� ���
                ������ FreePtr ��� ������ ���������� ������
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;    /* ��� ����� �������� � ������� ������� ����� ��� ����� ��� ���������, ������� ���� �������� */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
   ����������: ���� (��������) ������ ��� ������� �� ���� �����
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* �������:    ���� ������ List ��� ������� �� ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ����.
   ����������: True �� � ����������� ����� ����� ���� ��� false �����������
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* �������:    ��� ����������� �����.
   ����������: ������� �� � ����������� ����� ����� ������.
   ����������: True �� � ���������������� ����� ������, false �����������
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* �������:   ��� ������ Node ��� ��� ������ FreePtr.
  ����������: ������ ���� "��������" ����� ��� ��� ������� � ������� P.
  ����������: ��� ������ P ��� ��� �������������  ������ FreePtr
                ��� ����������� ��� ����� ��������� �����
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* �������:    ��� ������ Node, ��� ���������� �� �������� ��� ���������� ������,
                ���� ������ TempPtr ��� ��� ������ FreePtr.
   ����������: ���������� ��� �������� ��� ����� ���� ����� ������� � TempPtr.
   ����������: ��� ������������� ������ Node ��� ��� ������ FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1; /* ��� �������� ������, ��������� ��� �� ��������� ����
                        �������� �� ������������ ������ */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* �������:    ��� ����������� �����, ��� ������ Node, ��� ������ PredPtr ���
                ��� �������� Item.
  ����������: ������� ��� ����������� �����, �� ��� ����� ������, �� ��������
                Item ���� ��� ��� ����� ���� ����� ������� � ������� PredPtr.
  ����������: ��� ������������� ����������� �����, ��� ������������� ������ Node
                ��� ��� ������ FreePtr.
  ������:     ������ ������� ������, �� � ����������� ����� ����� ������
*/
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
/* �������:   ��� ����������� ����� ��� ��� ������ PredPtr ��� �������
                ���� ����������� ����� ��� ����� ��� �� ���������.
  ����������: ��������� ��� �� ����������� �����, �� ��� ����� ����,
                ��� ����������� ����� ��� ����� ���� ����� ������� � PredPtr.
  ����������: ��� ������������� ����� ��� �� ������ FreePtr.
  ������:     ������ ����� ������, �� � ����������� ����� ����� ����
*/
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

void TraverseLinked(ListPointer List, NodeType Node[])
/* �������:    ��� ����������� �����.
   ����������: ����� �������� ��� ������������ ������, �� ��� ����� ����.
   ������:     ��������� ��� ��� �����������
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item,
ListPointer *PredPtr){
    {
// ������ ��� ����������
boolean stop; //��� ��� ���������� ��� ��������� ��� List �� �� �������� ���
//�������
boolean found;
  ListPointer current;
//������������ stop ��� found
found=FALSE;
stop=FALSE;
//������������ ��� ������������ *PredPtr �� ������� �� ����������� ��� 1�
//������ ��� ������ //�� ���� ��� ���� � ����� ����� ����
 *PredPtr = NilValue;
//�� � List ��� ����� ����
if(!EmptyList(List))
 {
 //������������ ��� ������������ current �� ������� �� 1� ����� ��� ������
  current = List;   //mpeni stin arxi tis listas gia na arxisi na psaxni
 while(current!=-1 && !stop) {
 if(Node[current].Data>=Item) {
//�� Item � ������� � ��� ������� ��� List
stop=TRUE;
// found TRUE � FALSE �� ������� � ���
 found=TRUE;
 }
 else{
 // ��������� ���� ������������� *PredPtr & current
 //� *PredPtr �� ������� �� ����� ���� �������� ����� ��� ������
//o current �� ������� ��� ������� ����� ��� ������
*PredPtr = current;
 current = Node[current].Next;  //metavenume ston epomeno
 }
 }
 }
 else{ //�� �������� ��� �������
found=FALSE;}
return found;
}


}
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}



int main(){
boolean found;
char ch;
ListPointer AList;           //dilosi listas
NodeType Node[NumberOfNodes];
ListPointer FreePtr,PredPtr;       //dixtes p dixnun to diathesimo stixio kai to proigumeno stixio
ListElementType AnItem;   //to item p vazo kai vgazw apo tin oura
InitializeStoragePool(Node, &FreePtr);      //dimiurgi afto pou lei posus diathesimus komvus iparxun
CreateList(&AList);      //dimiurgia listas
printf("---------------Question C--------------------\n");
printf("--------------Storage pool------------------\n");
printAll(AList, FreePtr, Node);    //emfanizi tus diathesimus komvus
printf("---------------Question D--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(AList,Node);        //emfanizi tin lista
printf("---------------Question E--------------------\n");
do
{
printf("Give us a number:");
scanf("%d", &AnItem);

found=Search(FreePtr,AList,Node,AnItem,&PredPtr); //elexi an iparxi o arithmos stin lista
Insert(&AList, Node,&FreePtr, PredPtr, AnItem);   //isagi ton arithmo stin lista

printf("\nContinue Y/N: ");


do
{
scanf(" %c", &ch);
} while (toupper(ch)!= 'N'  && toupper(ch) != 'Y');
} while (toupper(ch)!='N');
printf("---------------Question F--------------------\n");
printf("--------------Storage pool------------------\n");
printAll(AList, FreePtr, Node);
printf("---------------Question G--------------------\n");
printf("--------------Linked list--------------------\n");
TraverseLinked(AList,Node);
printf("---------------Question H--------------------\n");
if(EmptyList(AList)){
    printf("Empty List\n");
}
else{
    printf("Not an Empty List");
}
printf("\n---------------Question I--------------------\n");
if(FullList(AList)){
    printf("Full List");
}
else{
    printf("Not a Full List");
}
printf("\n---------------Question J--------------------\n");
printf("-----------------Search for a number-----------------\n");
while(1){
printf("Give a number ");
scanf("%d",&AnItem);
found=Search(FreePtr,AList,Node,AnItem,&PredPtr);
if(found==TRUE){
printf("The number is in the list and its predecessor is in position %d\n",PredPtr);
}
else{
    printf("The number is not in the list");
    break;
} }
return 0;
}
