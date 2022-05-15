#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define  MaxElements 10          //�� ������� ������ ��� ��������� ��� �����

typedef float  HeapElementType;    //� ����� ��������� ��� ��������� ��� �����
typedef  struct {
     HeapElementType key;
    // int Data;                // ����������� ����� ��� �� ����������� �������� ���� ������
} HeapNode;


typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMinHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMinHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMinHeap(HeapType *Heap, HeapNode *Item);
int main () {
HeapType AHeap;
    HeapNode AnItemxx;
    int m;
    FILE *fp;

    // Διάβασε το m
    printf("Give m: ");
    scanf("%d", &m);

    CreateMinHeap(&AHeap); // Δημιούργησε τον σωρό ελαχίστων

    fp=fopen("transactions.txt","r"); // Άνοιξε το αρχείο για ανάγνωση

    while(!feof(fp)) // Όσο δεν έφτασες στο τέλος του αρχείου
    {
        fscanf(fp, "%f [^\n]", &AnItemxx.key); // Διάβασε την συναλλαγή
        InsertMinHeap(&AHeap, AnItemxx); // Εισαγωγή της συναλλαγής στον σωρό ελαχίστων
        if(AHeap.Size>m) // Αν το μέγεθος του σωρού ξεπέρασε το m
            DeleteMinHeap(&AHeap, &AnItemxx); // Διαγραφή του ελάχιστου στοιχείου από τον σωρό
    }
    PrintHeap(AHeap); // Εμφάνισε το μέγεθος και το περιεχόμενο του σωρού
    printf("Transactions\n");

    while(!EmptyHeap(AHeap)) // Όσο ο σωρός δεν είναι κενός
    {
        DeleteMinHeap(&AHeap, &AnItemxx); // Διαγραφή του ελάχιστου στοιχείου από τον σωρό
        printf("%.2f ", AnItemxx.key); // Εμφάνιση του στοιχείου
    }

    printf("\n");
}

PrintHeap(HeapType Heap)
{
    int i;
    printf("Data structure size =%d\n", Heap.Size); // Εμφάνισε “Data structure size=”, μέγεθος του σωρού
    for (i=1; i<=Heap.Size;i++)
        printf("%.2f ",Heap.Element[i].key); // Εμφάνισε το στοιχείο του σωρού που βρίσκεται στη θέση της τιμής της μεταβλητής ελέγχου
    printf(" \n");
}


void CreateMinHeap(HeapType *Heap)
/* ����������: ���������� ��� ���� ����.
   ����������: ��� ���� ����
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* �������:    ��� ���� Heap.
   ����������: ������� �� � ����� ����� �����.
   ����������: TRUE �� � ����� ����� �����, FALSE �����������
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* �������:    ��� ����.
   ����������: ������� �� � ����� ����� �������.
   ����������: TRUE �� � ����� ����� �������, FALSE �����������
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
/*  �������:    ��� ���� Heap ��� ��� �������� ��������� Item .
    ����������: ������� �� �������� Item ��� ����, �� � ����� ��� ����� �������.
    ����������: ��� ������������� ����.
    ������:     ������ ������� ����� �� � ����� ����� �������
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key < Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMinHeap(HeapType *Heap, HeapNode *Item)
/* �������:    ��� ���� Heap.
   ����������: ������ ��� ��������� �� ���������� �������� ��� �����.
   ����������: �� ���������� �������� Item ��� ����� ��� ��� ������������� ����
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key > (*Heap).Element[child+1].key)
                    child++;
            if (last.key <= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}
