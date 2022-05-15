#include<stdio.h>
#include<stdlib.h>
#define QueueLimit 20  //�� ���� �������� ��� �����

typedef int QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                                  ���������� ����� int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

int main(){
QueueType Q1,Q2;
CreateQ(&Q1);
CreateQ(&Q2);
for(int i=1;i<=QueueLimit;i++){
    if(i%2==0){
        AddQ(&Q1,i);
    }
    else{
        AddQ(&Q2,i);
    }
}
printf("Size of EvenQueue: %d \n",Q1.Rear);
TraverseQ(Q1);
printf("Size of OddQueue: %d \n",Q2.Rear);
TraverseQ(Q2);
int c;
int i= rand() % 20;
printf("random number of items = %d \n",i);
for(int x=0;x<i;x++){
    RemoveQ(&Q1,&c);
    AddQ(&Q1,c);
}
printf("Size of EvenQueue: %d \n",Q1.Rear);
TraverseQ(Q1);
i= rand() % 20;
printf("random number of items =%d\n",i);
for(int x=0;x<i;x++){
    RemoveQ(&Q2,&c);
    AddQ(&Q2,c);
}
printf("Size of OddQueue: %d \n",Q2.Rear);
TraverseQ(Q2);
return 0;
}
void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}

void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}
