#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10	/*������е��������	*/

int front=-1;/*ָ����е�ǰ��*/
int rear=-1;/*ָ����еĺ��*/

struct list/*����ͼ�Ķ���ṹ*/
{
   int x;				/*��������*/
   struct list *next;	/*ָ����һ�������ָ��*/
};
typedef struct list node;
typedef node *link;
struct GraphLink
{
   link first;
   link last;       
};

int run[9];/*������¼�������Ƿ������*/
int queue[MAXSIZE];
struct GraphLink Head[9];


void insert(struct GraphLink *temp,int x)
{
   link newNode;
   newNode=(link)malloc(sizeof(node));
   newNode->x=x;
   newNode->next=NULL;  
   if(temp->first==NULL)
   { 
      temp->first=newNode;
      temp->last=newNode;
   }
   else 
   {
	 temp->last->next=newNode;
	 temp->last=newNode;
   }
}
/*�����ݼ������*/
void enqueue(int value)
{
   if(rear>=MAXSIZE) return;
   rear++;
   queue[rear]=value;
}
/*�Ӷ���ȡ������*/
int dequeue() 
{
   if(front==rear) return -1;
   front++;
   return queue[front];
}
/*������ȱ�����*/
void bfs(int current)
{
   link tempnode; /*��ʱ�Ľڵ�ָ��*/
   enqueue(current); /*����һ������������*/
   run[current]=1; /*���������Ķ�������Ϊ1*/
   printf("[%d]",current); /*����ñ������Ķ���*/
   while(front!=rear) { /*�жϵ�ǰ�Ƿ�Ϊ�ն���*/
      current=dequeue(); /*������Ӷ�����ȡ��*/
      tempnode=Head[current].first; /*�ȼ�¼��ǰ�����λ��*/
      while(tempnode!=NULL)
      {
         if(run[tempnode->x]==0)
         {
            enqueue(tempnode->x);
            run[tempnode->x]=1; /*��¼���߷ù�*/
            printf("[%d]",tempnode->x);
         }
         tempnode=tempnode->next;
      }
   }
} 
void print(struct GraphLink temp)
{
   link current=temp.first;
   while(current!=NULL)
   {
      printf("[%d]",current->x);
      current=current->next;
   }
   printf("\n");
}

int main()
{
/*�����洢ͼ�ı��ߵ�����*/
   int Data[20][2] =  
   { {1,2},{2,1},{1,5},{5,1},{2,4},{4,2},{2,3},{3,2},{3,4},{4,3},
   {5,3},{3,5},{4,5},{5,4}};
   int DataNum;			
   int i,j;				
   printf("ͼ���ڽӱ����ݣ�\n"); /*��ӡͼ���ڽӱ�����*/
   for( i=1 ; i<6 ; i++ )
   { /*���а˸�����*/
      run[i]=0; /*�������ж������δ������*/
      printf("����%d=>",i);
      Head[i].first=NULL;
      Head[i].last=NULL;                 
	  for( j=0 ; j<20 ;j++)
      {
	     if(Data[j][0]==i)
         { /*�����������ͷ��ȣ���Ѷ����������*/
	        DataNum = Data[j][1];          
	        insert(&Head[i],DataNum);
	     }
	   }
	      print(Head[i]);/*���ͼ���ڽӱ�����*/
    } 	
    printf("������ȱ������㣺\n");/*���������ȱ����Ķ���*/
    bfs(1);
    printf("\n");
	system("pause");
	return 0;
}
