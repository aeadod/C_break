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
/*方法enqueue:队列数据的加入*/
void enqueue(int value) 
{
   QueueByLinkedList node; /*建立节点*/
   node=(QueueByLinkedList)malloc(sizeof(QueueNode));
   node->data=value;
   node->next=NULL;
   /*检查是否为空队列*/
   if (rear==NULL)
      front=node;/*新建立的节点成为第1个节点*/
   else
      rear->next=node;/*将节点加入到队列的尾端*/
   rear=node;/*将队列的尾端指针指向新加入的节点*/
}
int dequeue(int action)/*方法dequeue:队列数据的取出*/
{
   int value;
   QueueByLinkedList tempNode,startNode;
   /*从前端取出数据*/
   if (!(front==NULL) && action==1) 
   {
     if(front==rear) rear=NULL;
     value=front->data;/*将队列数据从前端取出*/
     front=front->next;/*将队列的前端指针指向下一个*/
     return value;
   }
   /*从尾端取出数据*/
   else if(!(rear==NULL) && action==2) 
   {
     startNode=front;/*先记下前端的指针*/
     value=rear->data;/*取出当前尾端的数据*/
     /*寻找最尾端节点的前一个节点*/
     tempNode=front;
     while (front->next!=rear && front->next!=NULL) 
     { 
           front=front->next;
           tempNode=front;
     }
     front=startNode;/*记录从尾端取出数据后的队列前端指针*/
     rear=tempNode;/*记录从尾端取出数据后的队列尾端指针*/
     /*下一行程序是指当队列中仅剩下最后一个节点时,
     取出数据后便将front及rear指向null*/
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
   printf("以链表来实现双向队列\n");
   printf("====================================\n");
   
   do
     {
      printf("加入请按a, 取出请按d, 结束请按e:");
      ch=getche();
      printf("\n");
      if(ch=='a')
      {
       printf("加入的元素值:"); 
       scanf("%d",&item);
       enqueue(item);
       }
       else if(ch=='d')
       {
       temp=dequeue(1);
       printf("从双向队列前端按序取出的元素数据值为：%d\n",temp);
       temp=dequeue(2);
       printf("从双向队列尾端按序取出的元素数据值为：%d\n",temp);
       }
       else 
         break;
        } while(ch!='e');
       
  system("pause");      
  return 0; 
}
