#include <stdio.h>
#include <stdlib.h>

struct student
{ 
	int num;
	char name[10];
	int score;
	struct student *next;
};
typedef struct student node;
typedef node *link;

int main()
{  
	link newnode,ptr,delptr;             /*������������ṹָ��*/
	int i;
	printf("������ 5 ��ѧ�����ݣ�\n");
	delptr=(link)malloc(sizeof(node));   /*delptr�ݵ�����ͷ*/
	if (!delptr)
	{  
		printf("[Error!!�ڴ����ʧ��!]\n");
		exit(1);
	}
	printf("���������ţ�");
	scanf("%d",&delptr->num);
	printf("������������");
	scanf("%s",delptr->name);
	printf("������ɼ���");
	scanf("%d",&delptr->score);
	ptr=delptr;                          /*��������ͷ����ptrΪ��ǰ�ڵ�ָ��*/
	for (i=1;i<5;i++)
	{  
		newnode=(link)malloc(sizeof(node));  /*�����½ڵ�*/
		if(!newnode)
		{  
			printf("[Error!!�ڴ����ʧ��!\n");
			exit(1);
		}
		printf("���������ţ�");
		scanf("%d",&newnode->num);
		printf("������������");
		scanf("%s",newnode->name);
		printf("������ɼ���");
		scanf("%d",&newnode->score);
		newnode->next=NULL;
		ptr->next=newnode;          /*���½ڵ�����������*/
		ptr=ptr->next;              /*��ptr����������������*/
	}
    printf("\n  ѧ  ��  ��  ��\n");
    printf(" ����\t����\t�ɼ�\n=====================\n");
	ptr=delptr;                     /*��ptr�ص�����ͷ*/
	while(ptr!=NULL)
	{  
		printf("%3d\t%-s\t%3d\n",ptr->num,ptr->name,ptr->score);
	    delptr=ptr;
		ptr=ptr->next;              /*ptr���������������*/
        free(delptr);               /*�ͷ��ڴ�ռ�*/
	}
	system("pause");
	return 0;
}
