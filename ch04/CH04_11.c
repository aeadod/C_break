#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};
typedef struct Node QueueNode;
typedef QueueNode *QueueByLinkedList;
QueueByLinkedList front=NULL;
QueueByLinkedList rear=NULL;
/*����enqueue:�������ݵļ���*/
void enqueue(int value) 
{
   QueueByLinkedList node; /*�����ڵ�*/
   node=(QueueByLinkedList)malloc(sizeof(QueueNode));
   node->data=value;
   node->next=NULL;
   /*����Ƿ�Ϊ�ն���*/
   if (rear==NULL)
      front=node;/*�½����Ľڵ��Ϊ��1���ڵ�*/
   else
      rear->next=node;/*���ڵ���뵽���е�β��*/
   rear=node;/*�����е�β��ָ��ָ���¼���Ľڵ�*/
}
int dequeue(int action)/*����dequeue:�������ݵ�ȡ��*/
{
   int value;
   QueueByLinkedList tempNode,startNode;
   /*��ǰ��ȡ������*/
   if (!(front==NULL) && action==1) 
   {
     if(front==rear) rear=NULL;
     value=front->data;/*���������ݴ�ǰ��ȡ��*/
     front=front->next;/*�����е�ǰ��ָ��ָ����һ��*/
     return value;
   }
   /*��β��ȡ������*/
   else if(!(rear==NULL) && action==2) 
   {
     startNode=front;/*�ȼ���ǰ�˵�ָ��*/
     value=rear->data;/*ȡ����ǰβ�˵�����*/
     /*Ѱ����β�˽ڵ��ǰһ���ڵ�*/
     tempNode=front;
     while (front->next!=rear && front->next!=NULL) 
     { 
           front=front->next;
           tempNode=front;
     }
     front=startNode;/*��¼��β��ȡ�����ݺ�Ķ���ǰ��ָ��*/
     rear=tempNode;/*��¼��β��ȡ�����ݺ�Ķ���β��ָ��*/
     /*��һ�г�����ָ�������н�ʣ�����һ���ڵ�ʱ,
     ȡ�����ݺ�㽫front��rearָ��null*/
     if ((front->next==NULL) || (rear->next==NULL)) 
     { 
         front=NULL;
         rear=NULL;
     }
     return value; 
   }
   else return -1;
}

int main()
{
   int temp,item;
   char ch;
   printf("��������ʵ��˫�����\n");
   printf("====================================\n");
   
   do
     {
      printf("�����밴a, ȡ���밴d, �����밴e:");
      ch=getche();
      printf("\n");
      if(ch=='a')
      {
       printf("�����Ԫ��ֵ:"); 
       scanf("%d",&item);
       enqueue(item);
       }
       else if(ch=='d')
       {
       temp=dequeue(1);
       printf("��˫�����ǰ�˰���ȡ����Ԫ������ֵΪ��%d\n",temp);
       temp=dequeue(2);
       printf("��˫�����β�˰���ȡ����Ԫ������ֵΪ��%d\n",temp);
       }
       else 
         break;
        } while(ch!='e');
       
  system("pause");      
  return 0; 
}
