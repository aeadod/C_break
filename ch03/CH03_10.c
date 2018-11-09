#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct employee
{  
	int num,score;
	char name[10];
	struct employee *next;
};
typedef struct employee node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr->next!=head)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->next;
     }
     return ptr;
}

link insertnode(link head,link after,int num,int score,char name[10])   
{  
    link InsertNode;
    InsertNode=(link)malloc(sizeof(node));
    link CurNode=NULL;
    InsertNode->num=num;
    InsertNode->score=score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;
    if(InsertNode==NULL)
    {
       printf("�ڴ����ʧ��\n");
       return NULL;
    }
    else
    {
        if(head==NULL)/*�����ǿյ�*/
        {
           head=InsertNode;
           InsertNode->next=head;
           return head;
        }              
        else
        {    
            
            if(after->next==head) /*�����ڵ�������ͷ����λ��*/
            {  
               /*(1)�������ڵ��ָ��ָ������ͷ*/
               InsertNode->next=head;
               CurNode=head;
               while(CurNode->next!=head)
                  CurNode=CurNode->next;
               /*(2)�ҵ�����ĩβ������ָ��ָ�������ڵ�*/
               CurNode->next=InsertNode;
               /*(3)������ͷָ�������ڵ�*/
               head=InsertNode;
               return head;
             }
            else /*�����ڵ�������ͷ����ĵط�*/
            {
               /*(1)�������ڵ��ָ��ָ��after����һ���ڵ�*/  
               InsertNode->next=after->next;
               /*(2)���ڵ�after��ָ��ָ�������ڵ�*/ 
               after->next=InsertNode;
               return head; 
            }
        }
    }
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find;
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	printf("Ա����� нˮ Ա����� нˮ Ա����� нˮ Ա����� нˮ\n");
	printf("-------------------------------------------------------\n");

	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("[%2d] [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	head=(link)malloc(sizeof(node));     /*����������*/
	if(!head)
	{  
		printf("Error!! �ڴ�����ʧ��!!\n");
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++)                   /*��������*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;/*��ǰһ���ڵ�ָ���½����Ľڵ�*/ 
		ptr=newnode; /*�½ڵ��Ϊǰһ���ڵ�*/ 
	}
	newnode->next=head;/*�����һ���ڵ�ָ��ͷ�ڵ�ͳ��˻�״����*/ 
	while(1)
	{  
		printf("������Ҫ��������Ա�����,������ı�Ų��ڴ˴�����,\n");
        printf("�������Ա���ڵ㽫��Ϊ�˴��еĵ�һ���ڵ�,Ҫ�����������,������-1��");
		scanf("%d",&position);
		if(position==-1)    /*ѭ���ж�����*/
			break;
		else
		{  
			ptr=findnode(head,position);
			printf("�������²����Ա����ţ�");
			scanf("%d",&new_num);
			printf("�������²����Ա��нˮ��");
			scanf("%d",&new_score);
			printf("�������²����Ա��������");
			scanf("%s",new_name);
			head=insertnode(head,ptr,new_num,new_score,new_name);
		}
	}
	ptr=head;/*ָ���еĿ�ͷ*/
	printf("\n\tԱ�����    ����\tнˮ\n");         
	printf("\t==============================\n");

	do
	{
	    printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
		ptr=ptr->next;/*ָ����һ���ڵ�*/
    } while(head!=ptr && head!=head->next);
	system("pause");
	return 0;
}

