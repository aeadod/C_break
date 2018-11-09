#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INDEXBOX 7         /*��ϣ��Ԫ�ظ���*/
#define MAXNUM 13          /*���ݸ���*/
void creat_table(int);     /*����������ϣ���ӳ���*/
void print_data(int);      /*������ӡ��ϣ���ӳ���*/
int findnum(int);          /*������ϣ�����ӳ���*/
struct list
{  
	int val;
	struct list *next;
};
typedef struct list node;
typedef node *link;
node indextable[INDEXBOX];   /*������̬����*/

int main(void)
{  
	int i,num,data[MAXNUM];
	srand((unsigned)time(NULL));
	for(i=0;i<INDEXBOX;i++)     /*�����ϣ��*/
	{  
		indextable[i].val=i;
		indextable[i].next=NULL;
	}
	printf("ԭʼ���ݣ�\n\t");
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1;       /*���������ԭʼ����*/
		printf("[%2d] ",data[i]);     /*����ӡ����*/
		if (i%8==7)
			printf("\n\t");
	}
	printf("\n");
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]);    /*������ϣ��*/
	while(1)
	{  
		printf("�������������(1-30)������������-1��");
		scanf("%d",&num);
		if(num==-1)
			break;
		i=findnum(num);
		if(i==0)
			printf("#####û���ҵ� %d #####\n",num);
		else
			printf("�ҵ� %d�������� %d ��!\n",num,i);
	}
	printf("\n��ϣ��\n");
	for(i=0;i<INDEXBOX;i++)
		print_data(i);         /*��ӡ��ϣ��*/
	printf("\n");
	system("pause");
	return 0;
}
void creat_table(int val)    /*������ϣ���ӳ���*/
{  
	link newnode;
	link current;
	int hash;
	hash=val%7;              /*��ϣ��������7ȡ����*/
	newnode=(link)malloc(sizeof(node));
	current=(link)malloc(sizeof(node));
	newnode->val=val;
	newnode->next=NULL;
	*current=indextable[hash];
    if(current->next==NULL) 
        indextable[hash].next=newnode;
    else
        while(current->next!=NULL) current=current->next;
    current->next=newnode; /*���ڵ��������*/
}
void print_data(int val)    /*��ӡ��ϣ���ӳ���*/
{  
	link head;
	int i=0;
	head=indextable[val].next;   /*��ʼָ��*/
	printf("   %2d��\t",val);    /*������ַ*/
	while(head!=NULL)
	{  
		printf("[%2d]-",head->val);
		i++;
		if(i%8==7)              /*���Ƴ���*/
			printf("\n\t");
		head=head->next;
	}
	printf("\b \n");            /*������һ��"-"����*/
}
int findnum(int num)     /*��ϣ�����ӳ���*/
{  
	link ptr;
	int i=0,hash;
	hash=num%7;
	ptr=indextable[hash].next;
	while(ptr!=NULL)
	{  
		i++;
		if(ptr->val==num)
			return i;
		else
			ptr=ptr->next;
	}
	return 0;
}
