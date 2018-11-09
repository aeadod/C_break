#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10	/*定义队列的最大容量	*/

int front=-1;/*指向队列的前端*/
int rear=-1;/*指向队列的后端*/

struct list/*声明图的顶点结构*/
{
   int x;				/*顶点数据*/
   struct list *next;	/*指向下一个顶点的指针*/
};
typedef struct list node;
typedef node *link;
struct GraphLink
{
   link first;
   link last;       
};

int run[9];/*用来记录各顶点是否遍历过*/
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
/*把数据加入队列*/
void enqueue(int value)
{
   if(rear>=MAXSIZE) return;
   rear++;
   queue[rear]=value;
}
/*从队列取出数据*/
int dequeue() 
{
   if(front==rear) return -1;
   front++;
   return queue[front];
}
/*广度优先遍历法*/
void bfs(int current)
{
   link tempnode; /*临时的节点指针*/
   enqueue(current); /*将第一个顶点加入队列*/
   run[current]=1; /*将遍历过的顶点设置为1*/
   printf("[%d]",current); /*输出该遍历过的顶点*/
   while(front!=rear) { /*判断当前是否为空队列*/
      current=dequeue(); /*将顶点从队列中取出*/
      tempnode=Head[current].first; /*先记录当前顶点的位置*/
      while(tempnode!=NULL)
      {
         if(run[tempnode->x]==0)
         {
            enqueue(tempnode->x);
            run[tempnode->x]=1; /*记录已走访过*/
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
/*声明存储图的边线的数组*/
   int Data[20][2] =  
   { {1,2},{2,1},{1,5},{5,1},{2,4},{4,2},{2,3},{3,2},{3,4},{4,3},
   {5,3},{3,5},{4,5},{5,4}};
   int DataNum;			
   int i,j;				
   printf("图的邻接表内容：\n"); /*打印图的邻接表内容*/
   for( i=1 ; i<6 ; i++ )
   { /*共有八个顶点*/
      run[i]=0; /*设置所有顶点成尚未遍历过*/
      printf("顶点%d=>",i);
      Head[i].first=NULL;
      Head[i].last=NULL;                 
	  for( j=0 ; j<20 ;j++)
      {
	     if(Data[j][0]==i)
         { /*如果起点和链表头相等，则把顶点加入链表*/
	        DataNum = Data[j][1];          
	        insert(&Head[i],DataNum);
	     }
	   }
	      print(Head[i]);/*输出图的邻接表内容*/
    } 	
    printf("广度优先遍历顶点：\n");/*输出广度优先遍历的顶点*/
    bfs(1);
    printf("\n");
	system("pause");
	return 0;
}
