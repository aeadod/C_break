#include <stdio.h>
#include <stdlib.h>

struct list   /*��������ṹ*/
{  
	int num,score;
	struct list *next;
};
typedef struct list node;
typedef node *link;
link creat_link(int data[10][2],int num);
void print_link(link head);
link concat(link ptr1,link ptr2);

int main()
{  
	link ptr1,ptr2,ptr;
	int i,data1[6][2]={ 1002,25000,1004,30200,1005,28600,1007,29000,1011,35000,1013,54000 };
    int data2[6][2]={ 1022,17400,1024,22500,1035,28000,1040,42000,1045,35560,1056,29000};
	
	ptr1=creat_link(data1,6);   /*��������1*/
	ptr2=creat_link(data2,6);   /*��������2*/
	i=0;
	printf("\t\t    ԭ ʼ Ա �� �� �� �� �ݣ�\n");
	printf("\t   Ա����� н��   Ա����� н��  Ա����� н��\n");
	printf("\t   ===============================================\n");
	printf("   ���� 1 : ");
	print_link(ptr1);
	printf("   ���� 2 : " );
	print_link(ptr2);
	printf("\t    ==============================================\n");
	printf("���Ӻ�����");
	ptr=concat(ptr1,ptr2);    /*����*/
	print_link(ptr);
	system("pause");
	return 0;
}
link creat_link(int data[10][2],int num) /*���������ӳ���*/
{  
	int i;
	link head,ptr,newnode;
	for(i=0;i<num;i++)
	{  
		newnode=(link)malloc(sizeof(node));
		if(!newnode)
		{  
			printf("Error!! �ڴ����ʧ��!!\n");
			exit(i);
		}
		if(i==0)  /*��������ͷ*/
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else       /*�������������ڵ�*/
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
		newnode->next=head;
	}
	return ptr;    /*��������*/
}
void print_link(link head) /*��ӡ�����ӳ���*/
{  
	link ptr;
	int i=0;
	ptr=head->next;
	do 
	{  
		printf("[%2d-%3d] -> ",ptr->num,ptr->score);
		i++;
		if(i>=3)            /*ÿ�д�ӡ����Ԫ��*/
		{  
			printf("\n\t    ");
			i=0;
		}
		ptr=ptr->next;
	}while(ptr!=head->next);
	printf("\n");
}
link concat(link ptr1,link ptr2) /*���������ӳ���*/
{  
	link head;
	head=ptr1->next;   /*��ptr1��ptr2�У���������һ���ڵ�*/
	ptr1->next=ptr2->next;  /*�������ڵ��next�Ե�����*/
	ptr2->next=head;
	return ptr2;
}
