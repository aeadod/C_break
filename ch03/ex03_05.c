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
	link newnode,ptr,delptr;             /*声明三个链表结构指针*/
	int i;
	printf("请输入 5 个学生数据：\n");
	delptr=(link)malloc(sizeof(node));   /*delptr暂当链表头*/
	if (!delptr)
	{  
		printf("[Error!!内存分配失败!]\n");
		exit(1);
	}
	printf("请输入座号：");
	scanf("%d",&delptr->num);
	printf("请输入姓名：");
	scanf("%s",delptr->name);
	printf("请输入成绩：");
	scanf("%d",&delptr->score);
	ptr=delptr;                          /*保留链表头，以ptr为当前节点指标*/
	for (i=1;i<5;i++)
	{  
		newnode=(link)malloc(sizeof(node));  /*建立新节点*/
		if(!newnode)
		{  
			printf("[Error!!内存分配失败!\n");
			exit(1);
		}
		printf("请输入座号：");
		scanf("%d",&newnode->num);
		printf("请输入姓名：");
		scanf("%s",newnode->name);
		printf("请输入成绩：");
		scanf("%d",&newnode->score);
		newnode->next=NULL;
		ptr->next=newnode;          /*把新节点加在链表后面*/
		ptr=ptr->next;              /*让ptr保持在链表的最后面*/
	}
    printf("\n  学  生  成  绩\n");
    printf(" 座号\t姓名\t成绩\n=====================\n");
	ptr=delptr;                     /*让ptr回到链表头*/
	while(ptr!=NULL)
	{  
		printf("%3d\t%-s\t%3d\n",ptr->num,ptr->name,ptr->score);
	    delptr=ptr;
		ptr=ptr->next;              /*ptr按序往后遍历链表*/
        free(delptr);               /*释放内存空间*/
	}
	system("pause");
	return 0;
}
