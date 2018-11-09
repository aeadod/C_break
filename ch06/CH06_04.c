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

void dfs(int current)                  /*������Ⱥ���*/
{  
	link ptr;
	run[current]=1;
	printf("[%d] ",current);
	ptr=head[current]->next;
	while(ptr!=NULL)
	{		
		if (run[ptr->val]==0)        /*���������δ������*/
			dfs(ptr->val);         /*�ͽ���dfs�ĵݹ����*/
		ptr=ptr->next;
	}
}
int main()
{  
	link ptr,newnode;
	int data[20][2]={{1,2},{2,1},{1,3},{3,1},   /*�����洢ͼ�ıߵ�����*/
					{2,4},{4,2},{2,5},{5,2},
					{3,6},{6,3},{3,7},{7,3},
					{4,8},{8,4},{5,8},{8,5},{6,8},{8,6},{8,7},{7,8}};
	int i,j;

	for (i=1;i<=8;i++)                        /*���а˸�����*/
	{  
		run[i]=0;                          /*�������ж������δ������*/
		head[i]=(link)malloc(sizeof(node));   
		head[i]->val=i;                     /*���ø�������ͷ�ĳ�ֵ*/
		head[i]->next=NULL;
		ptr=head[i];                       /*����ָ��Ϊ����ͷ*/
		for(j=0;j<20;j++)                   /*��ʮ������*/
		{  
			if(data[j][0]==i)     /*�����������ͷ��ȣ���Ѷ����������*/
			{  
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];
				newnode->next=NULL;
				do
				{
					ptr->next=newnode;        /*�����½ڵ�*/
					ptr=ptr->next;
				}while(ptr->next!=NULL);
			}
		} 
	}
	printf("ͼ���ڽӱ����ݣ�\n");      /*��ӡͼ���ڽӱ�����*/
	for(i=1;i<=8;i++)
	{
		ptr=head[i];
		printf("���� %d=> ",i);
		ptr = ptr->next;
		while(ptr!=NULL)
		{
			printf("[%d] ",ptr->val);
			ptr=ptr->next;
		}
		printf("\n");
	}

	printf("������ȱ������㣺\n");      /*��ӡ������ȱ����Ķ���*/
	dfs(1);
	printf("\n");
	system("pause");
	return 0;
}
