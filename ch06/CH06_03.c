#include <stdio.h>
#include <stdlib.h>

struct list
{  int val;
   struct list *next;
};
typedef struct list node;
typedef node *link;
struct list head[6];       /*����һ���ڵ���������*/
int main()
{  
	link ptr,newnode;
	char data[14][2]={{1,2},{2,1},{2,5},{5,2},     /*ͼ����������*/
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	int i,j;
	printf("ͼ�ε��ڽӱ����ݣ�\n");
	printf("----------------------------------\n");
	for (i=1;i<6;i++)
	{  
		head[i].val=i;         /*����ͷhead*/
		head[i].next=NULL;
		printf("���� %d =>",i);  /*�Ѷ���ֵ��ӡ����*/
		ptr=&(head[i]);          /*�ݴ�ڵ�ptr*/
		for (j=0;j<14;j++)       /*����ͼ������*/
		{  
			if (data[j][0]==i)    /*����ڵ�ֵ=i������ڵ㵽����ͷ*/
			{  
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];        /*�����½ڵ㣬ֵΪ�յ�ֵ*/
				newnode->next=NULL;
				while(ptr!=NULL)                /*�ж��Ƿ�Ϊ�����β��*/
					ptr=ptr->next;
				ptr=newnode;                   /*�����½ڵ�*/
				printf("[%c] ",64+newnode->val);  /*��ӡ���ڶ���*/
			}
		}   
		printf("\n");
	}
	system("pause");
	return 0;
}
