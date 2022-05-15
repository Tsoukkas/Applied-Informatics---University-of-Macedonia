#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define QueueLimit 4

typedef struct{
int ora_afiksis,start;
int xronos_anamonis,end;
} QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                                ���������� ����� int */
typedef enum {FALSE, TRUE} boolean;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

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
void TraverseQ(char a[],QueueType Queue) {
	int current;
	int i=1;
	if(!EmptyQ(Queue)){
        printf("%s\n",a);
	current = Queue.Front;
	printf("Client \t\t\tStart\tEnd\tArrival\tStay\n");     //ta emfanizi stixismena
	while (current != Queue.Rear) {
        printf("Client %d \t\t%d\t%d\t%d\t%d\n",i, Queue.Element[current].start,Queue.Element[current].end,Queue.Element[current].ora_afiksis,Queue.Element[current].xronos_anamonis);
		current = (current + 1) % QueueLimit;
		i++;
	} }
	else{
	printf("%s is empty\n",a);
}
printf("\n"); }

void ReadCustomer(QueueType *Queue){
QueueElementType tmpCustomer;
scanf("%d,%d",&tmpCustomer.ora_afiksis,&tmpCustomer.xronos_anamonis);
tmpCustomer.start=-1;
tmpCustomer.end=-1;
AddQ(Queue,tmpCustomer);
}

QueueType TimesInQueue(QueueType *Queue){
int earliestStart =0; //������ ������� ������������
int currentStart=0; //��� ������� ������������ ��� �������� ������
int currentEnd=0; //��� ����� ������������ ��� �������� ������
QueueType QueueServiced; //���� ���������������
QueueElementType CurrentCust;
CreateQ(&QueueServiced);
while(!(EmptyQ(*Queue))){
//�������� ��� ������ ��� ��� ���� ��� ����� ��������
RemoveQ(&(*Queue),&CurrentCust);
//�� � ��� ������ ��� ������ ����� ���� ��� ����� �������
//������������
if(CurrentCust.ora_afiksis>earliestStart){
//���� ��� �������� ��� ������� ��� �� ��� ��� ������ ������
currentStart=CurrentCust.ora_afiksis;
}
else{
//���� ��� �������� ��� ������� ��� �� ��� ����� �������
//������������
currentStart=earliestStart; }
//��������� ��� ��� ����� ������������ ��� ��� �������� ������
 currentEnd=currentStart +CurrentCust.xronos_anamonis;
//��������� ��� ����� ������� ������������ ��� ��� ������� ������
earliestStart=currentEnd;
//��������� ��� �������� ������ �� �� ��� ��� ��������
CurrentCust.start=currentStart;
CurrentCust.end= currentEnd;
//�������� ��� �������� ������ ���� ���� ���������������
AddQ(&QueueServiced,CurrentCust);
}
//��������� ��� ���� ���������������
return QueueServiced;
}

int main(){
QueueType WaitingQueue,ServiceQueue;
CreateQ(&WaitingQueue);
CreateQ(&ServiceQueue);          //dilosi kai dimiurgia ourwn
for(int i=1;i<QueueLimit;i++){
    printf("Give: arrival time,stay time for client %d:",i);
    ReadCustomer(&WaitingQueue);
}                         //kataxorisi oras p tha pai o pelatis kai poses ores tha mini
TraverseQ("Waiting Queue",WaitingQueue);
ServiceQueue=TimesInQueue(&WaitingQueue);
TraverseQ("Waiting Queue",WaitingQueue);
TraverseQ("Service Queue",ServiceQueue);
return 0;
}
