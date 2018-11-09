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
link del_ptr(link head,link ptr);
int main()
{  
	link head,ptr,newnode;
	int i,j,find;
	int findword=0;
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
    printf("Ա����� нˮ Ա����� нˮ Ա����� нˮ Ա����� нˮ\n");
	printf("-------------------------------------------------------\n");

	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("%2d  [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	head=(link)malloc(sizeof(node));     /*��������ͷ*/
	if(!head)
	{  
		printf("Error!! �ڴ����ʧ��!!\n");
		exit(1);
	}
	head->num=data[0][0];
	strcpy(head->name,namedata[0]);
	head->score=data[0][1];
	head->next=NULL;
	
    ptr=head;
	for(i=1;i<12;i++)                   /*��������*/
	{  
		newnode=(link)malloc(sizeof(node));
		newnode->num=data[i][0];
		strcpy(newnode->name,namedata[i]);
		newnode->score=data[i][1];
		newnode->num=data[i][0];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	while(1)
	{  
		printf("\n������Ҫɾ����Ա�����,Ҫ�����������,������-1��");
		scanf("%d",&findword);
		if(findword==-1)             /*ѭ���ж�����*/
			break;
		else
		{  
			ptr=head;
			find=0;
			while (ptr!=NULL)
			{  
				if(ptr->num==findword)     
				{                       
					ptr=del_ptr(head,ptr);    
					find++;
					head=ptr;
					break;
				}
				ptr=ptr->next;
			}
			if(find==0)
			printf("######û���ҵ�######\n");
		}
	}
	ptr=head;
	printf("\n\t����\t    ����\t�ɼ�\n");          /*��ӡʣ����������*/
	printf("\t==============================\n");
	while(ptr!=NULL)
	{  
		printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
		ptr=ptr->next;
	}
	system("pause");
	return 0;
}
link del_ptr(link head,link ptr)       /*ɾ���ڵ��ӳ���*/
{  
	link top;
	top=head;
	if(ptr->num==head->num)                     /*[����1]:ɾ����������ͷ��*/
	{  
		head=head->next;
			printf("��ɾ���� %d ��Ա�� ������%s н��:%d\n",ptr->num,ptr->name,ptr->score);
	}
	else
	{  
		while(top->next!=ptr)          /*�ҵ�ɾ�����ǰһ��λ��*/
			top=top->next;
		if(ptr->next==NULL)            /*ɾ��������ĩβ�Ľڵ�*/
		{  
			top->next=NULL;
	 		printf("��ɾ���� %d ��Ա�� ������%s н��:%d\n",ptr->num,ptr->name,ptr->score);
		}
		else                           /*ɾ���������м����һ�ڵ�*/
		{  
			top->next=ptr->next;
				printf("��ɾ���� %d ��Ա�� ������%s н��:%d\n",ptr->num,ptr->name,ptr->score);
		}
	}
	free(ptr);                        /*�ͷ��ڴ�ռ�*/
	return head;                      /*��������*/
}
