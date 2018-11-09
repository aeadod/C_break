#include <stdio.h>
#include <stdlib.h>
#define VERTS	6                /*ͼ�Ķ�����*/

struct edge                      /*�����ߵĽṹ*/
{  
	int from,to;
	int find,val;
	struct edge* next;
};
typedef struct edge node;
typedef node* mst;
int v[VERTS+1];
mst findmincost(mst head)                 /*��ʾ�ɱ���С�ı�*/
{
	int minval=100;
	mst ptr,retptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->val<minval&&ptr->find==0)
		{                                  /*����ptr->val��ֵС��minval*/
			minval=ptr->val;			   /*�Ͱ�ptr->val��Ϊ��Сֵ*/
			retptr=ptr;                    /*���Ұ�ptr��¼����*/
		}
		ptr=ptr->next;
	}
	retptr->find=1;                        /*��retptr��Ϊ���ҵ��ı�*/
	return retptr;                         /*����retptr*/
}
void mintree(mst head)                     /*��С�ɱ�����������*/
{
	mst ptr,mceptr;
	int i,result=0;
	ptr=head;

	for(i=0;i<=VERTS;i++)
		v[i]=0;

	while(ptr!=NULL)
	{
		mceptr=findmincost(head);
		v[mceptr->from]++;
		v[mceptr->to]++;
		if(v[mceptr->from]>1&&v[mceptr->to]>1)
		{
			v[mceptr->from]--;
			v[mceptr->to]--;
			result=1;
		}
		else
			result=0;
		if(result==0)
			printf("��ʼ���� [%d] -> ��ֹ���� [%d] -> ·������ [%d]\n",mceptr->from,mceptr->to,mceptr->val);
		ptr=ptr->next;
	}
}

int main()
{  
	int data[10][3]={{1,2,6},{1,6,12},{1,5,10},{2,3,3},    /*�ɱ�������*/
                    {2,4,5},{2,6,8},{3,4,7},{4,6,11},
					{4,5,9},{5,6,16}};
	int i,j;
	mst head,ptr,newnode;
	head=NULL;
	
	for(i=0;i<10;i++)                    /*����ͼ������*/
	{  
		for(j=1;j<=VERTS;j++)
		{  
			if(data[i][0]==j)
			{  
				newnode=(mst)malloc(sizeof(node));
				newnode->from=data[i][0];
				newnode->to=data[i][1];
				newnode->val=data[i][2];
				newnode->find=0;
				newnode->next=NULL;
				if(head==NULL)
				{  
					head=newnode;
					head->next=NULL;
					ptr=head;
				}   
				else
				{  
					ptr->next=newnode;
					ptr=ptr->next;
				}
			}
		}
	}
	
	printf("-------------------------------------------------\n");
	printf("������С�ɱ���������\n");
	printf("-------------------------------------------------\n");
	mintree(head);                        /*������С�ɱ�������*/
	system("pause");
	return 0;
}
