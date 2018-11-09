#include <stdio.h>
#include <stdlib.h>

struct list
{  int val;
   struct list *next;
};
typedef struct list node;
typedef node *link;
struct list head[6];       /*声明一个节点类型数组*/
int main()
{  
	link ptr,newnode;
	char data[14][2]={{1,2},{2,1},{2,5},{5,2},     /*图形数组声明*/
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	int i,j;
	printf("图形的邻接表内容：\n");
	printf("----------------------------------\n");
	for (i=1;i<6;i++)
	{  
		head[i].val=i;         /*链表头head*/
		head[i].next=NULL;
		printf("顶点 %d =>",i);  /*把顶点值打印出来*/
		ptr=&(head[i]);          /*暂存节点ptr*/
		for (j=0;j<14;j++)       /*遍历图的数组*/
		{  
			if (data[j][0]==i)    /*如果节点值=i，加入节点到链表头*/
			{  
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];        /*声明新节点，值为终点值*/
				newnode->next=NULL;
				while(ptr!=NULL)                /*判断是否为链表的尾端*/
					ptr=ptr->next;
				ptr=newnode;                   /*加入新节点*/
				printf("[%c] ",64+newnode->val);  /*打印相邻顶点*/
			}
		}   
		printf("\n");
	}
	system("pause");
	return 0;
}
