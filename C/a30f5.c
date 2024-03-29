#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define  MaxElements 10

typedef int  HeapElementType;
typedef  struct {
     HeapElementType key;
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
void PrintHeap(HeapType Heap);

int main()
{
    HeapType AHeap;
    HeapNode Item;
    int m;
    FILE *fp;

    printf("Give m:");
    scanf("%d",&m);
    CreateMinHeap(&AHeap);

    fp=fopen("transactions.txt","r");

    while(!feof(fp)){
        fscanf(fp,"%f",&Item);
        InsertMinHeap(&AHeap,Item);
        if(AHeap.Size>m){
            DeleteMinHeap(&AHeap,&Item);
            }

            PrintHeap(AHeap);
            printf("Transactions");
            printf("\n");
            while(!EmptyHeap(AHeap)){
                DeleteMinHeap(&AHeap,Item.key);
                printf("%.2f",&Item);
            }


    }

	return 0;
}

void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Size=%d \n",Heap.Size);
     printf("N   L   R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%d, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%d, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%d \n",Heap.Element[r].key);
         else printf("\n");
     }
     printf("Heap array\n");
     for (i=1; i<=Heap.Size;i++)
        printf("%d ",Heap.Element[i].key);
    printf(" \n");
}


void CreateMinHeap(HeapType *Heap)
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
{
  return (Heap.Size==MaxElements);
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
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



