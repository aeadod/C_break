#include <stdio.h>
#include <stdlib.h>

struct list
{  
	int val;
    struct list *next;
};
typedef struct list node;
typedef node *link;
struct list* head[9];
int run[9];

void dfs(int current)                  /*深度优先函数*/
{  
	link ptr;
	run[current]=1;
	printf("[%d] ",current);
	ptr=head[current]->next;
	while(ptr!=NULL)
	{		
		if (run[ptr->val]==0)        /*如果顶点尚未遍历，*/
			dfs(ptr->val);         /*就进行dfs的递归调用*/
		ptr=ptr->next;
	}
}
int main()
{  
	link ptr,newnode;
	int data[20][2]={{1,2},{2,1},{1,3},{3,1},   /*声明存储图的边的数组*/
					{2,4},{4,2},{2,5},{5,2},
					{3,6},{6,3},{3,7},{7,3},
					{4,8},{8,4},{5,8},{8,5},{6,8},{8,6},{8,7},{7,8}};
	int i,j;

	for (i=1;i<=8;i++)                        /*共有八个顶点*/
	{  
		run[i]=0;                          /*设置所有顶点成尚未遍历过*/
		head[i]=(link)malloc(sizeof(node));   
		head[i]->val=i;                     /*设置各个链表头的初值*/
		head[i]->next=NULL;
		ptr=head[i];                       /*设置指针为链表头*/
		for(j=0;j<20;j++)                   /*二十条边线*/
		{  
			if(data[j][0]==i)     /*如果起点和链表头相等，则把顶点加入链表*/
			{  
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];
				newnode->next=NULL;
				do
				{
					ptr->next=newnode;        /*加入新节点*/
					ptr=ptr->next;
				}while(ptr->next!=NULL);
			}
		} 
	}
	printf("图的邻接表内容：\n");      /*打印图的邻接表内容*/
	for(i=1;i<=8;i++)
	{
		ptr=head[i];
		printf("顶点 %d=> ",i);
		ptr = ptr->next;
		while(ptr!=NULL)
		{
			printf("[%d] ",ptr->val);
			ptr=ptr->next;
		}
		printf("\n");
	}

	printf("深度优先遍历顶点：\n");      /*打印深度优先遍历的顶点*/
	dfs(1);
	printf("\n");
	system("pause");
	return 0;
}
