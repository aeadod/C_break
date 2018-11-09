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
    printf("员工编号 薪水 员工编号 薪水 员工编号 薪水 员工编号 薪水\n");
	printf("-------------------------------------------------------\n");

	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("%2d  [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	head=(link)malloc(sizeof(node));     /*建立链表头*/
	if(!head)
	{  
		printf("Error!! 内存分配失败!!\n");
		exit(1);
	}
	head->num=data[0][0];
	strcpy(head->name,namedata[0]);
	head->score=data[0][1];
	head->next=NULL;
	
    ptr=head;
	for(i=1;i<12;i++)                   /*建立链表*/
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
		printf("\n请输入要删除的员工编号,要结束输出过程,请输入-1：");
		scanf("%d",&findword);
		if(findword==-1)             /*循环中断条件*/
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
			printf("######没有找到######\n");
		}
	}
	ptr=head;
	printf("\n\t座号\t    姓名\t成绩\n");          /*打印剩余链表数据*/
	printf("\t==============================\n");
	while(ptr!=NULL)
	{  
		printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->score);
		ptr=ptr->next;
	}
	system("pause");
	return 0;
}
link del_ptr(link head,link ptr)       /*删除节点子程序*/
{  
	link top;
	top=head;
	if(ptr->num==head->num)                     /*[情形1]:删除点在链表头部*/
	{  
		head=head->next;
			printf("已删除第 %d 号员工 姓名：%s 薪资:%d\n",ptr->num,ptr->name,ptr->score);
	}
	else
	{  
		while(top->next!=ptr)          /*找到删除点的前一个位置*/
			top=top->next;
		if(ptr->next==NULL)            /*删除在链表末尾的节点*/
		{  
			top->next=NULL;
	 		printf("已删除第 %d 号员工 姓名：%s 薪资:%d\n",ptr->num,ptr->name,ptr->score);
		}
		else                           /*删除在链表中间的任一节点*/
		{  
			top->next=ptr->next;
				printf("已删除第 %d 号员工 姓名：%s 薪资:%d\n",ptr->num,ptr->name,ptr->score);
		}
	}
	free(ptr);                        /*释放内存空间*/
	return head;                      /*返回链表*/
}
