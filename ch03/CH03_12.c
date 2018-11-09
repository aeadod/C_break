#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct list   /*声明链表结构*/
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
	int i,data1[6][2],data2[6][2];
	srand((unsigned)time(NULL));
	for (i=1;i<=6;i++)
	{  
		data1[i-1][0]=i*2-1;
		data1[i-1][1]=rand()%49+52;
		data2[i-1][0]=i*2;
		data2[i-1][1]=rand()%49+52;
	}
	ptr1=creat_link(data1,6);   /*建立链表1*/
	ptr2=creat_link(data2,6);   /*建立链表2*/
	i=0;
	printf("\t\t    原 始 链 表 数 据：\n");
	printf("\t     座号 成绩   座号 成绩   座号 成绩\n");
	printf("\t    ==================================\n");
	printf("   链表 1 ：");
	print_link(ptr1);
	printf("   链表 2 ：");
	print_link(ptr2);
	printf("\t    ==================================\n");
	printf("连接后的链表：");
	ptr=concat(ptr1,ptr2);    /*连接链表*/
	print_link(ptr);
	system("pause");
	return 0;
}
link creat_link(int data[10][2],int num) /*建立链表子程序*/
{  
	int i;
	link head,ptr,newnode;
	for(i=0;i<num;i++)
	{  
		newnode=(link)malloc(sizeof(node));
		if(!newnode)
		{  
			printf("Error!! 内存分配失败!!\n");
			exit(i);
		}
		if(i==0)  /*建立链表头*/
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else       /*建立链表其他节点*/
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
		newnode->next=head;
	}
	return ptr;    /*返回链表*/
}
void print_link(link head) /*打印链表子程序*/
{  
	link ptr;
	int i=0;
	ptr=head->next;
	do 
	{  
		printf("[%2d-%3d] -> ",ptr->num,ptr->score);
		i++;
		if(i>=3)            /*每行打印三个元素*/
		{  
			printf("\n\t    ");
			i=0;
		}
		ptr=ptr->next;
	}while(ptr!=head->next);
	printf("\n");
}
link concat(link ptr1,link ptr2) /*连接链表子程序*/
{  
	link head;
	head=ptr1->next;   /*在ptr1和ptr2中，各找任意一个节点*/
	ptr1->next=ptr2->next;  /*把两个节点的next对调即可*/
	ptr2->next=head;
	return ptr2;
}
