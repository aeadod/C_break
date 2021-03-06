#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INDEXBOX 7         /*哈希表元素个数*/
#define MAXNUM 13          /*数据个数*/
void creat_table(int);     /*声明建立哈希表子程序*/
void print_data(int);      /*声明打印哈希表子程序*/
int findnum(int);          /*声明哈希查找子程序*/
struct list
{  
	int val;
	struct list *next;
};
typedef struct list node;
typedef node *link;
node indextable[INDEXBOX];   /*声明动态数组*/

int main(void)
{  
	int i,num,data[MAXNUM];
	srand((unsigned)time(NULL));
	for(i=0;i<INDEXBOX;i++)     /*清除哈希表*/
	{  
		indextable[i].val=i;
		indextable[i].next=NULL;
	}
	printf("原始数据：\n\t");
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1;       /*随机数建立原始数据*/
		printf("[%2d] ",data[i]);     /*并打印出来*/
		if (i%8==7)
			printf("\n\t");
	}
	printf("\n");
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]);    /*建立哈希表*/
	while(1)
	{  
		printf("请输入查找数据(1-30)，结束请输入-1：");
		scanf("%d",&num);
		if(num==-1)
			break;
		i=findnum(num);
		if(i==0)
			printf("#####没有找到 %d #####\n",num);
		else
			printf("找到 %d，共找了 %d 次!\n",num,i);
	}
	printf("\n哈希表：\n");
	for(i=0;i<INDEXBOX;i++)
		print_data(i);         /*打印哈希表*/
	printf("\n");
	system("pause");
	return 0;
}
void creat_table(int val)    /*建立哈希表子程序*/
{  
	link newnode;
	link current;
	int hash;
	hash=val%7;              /*哈希函数除以7取余数*/
	newnode=(link)malloc(sizeof(node));
	current=(link)malloc(sizeof(node));
	newnode->val=val;
	newnode->next=NULL;
	*current=indextable[hash];
    if(current->next==NULL) 
        indextable[hash].next=newnode;
    else
        while(current->next!=NULL) current=current->next;
    current->next=newnode; /*将节点加在链表*/
}
void print_data(int val)    /*打印哈希表子程序*/
{  
	link head;
	int i=0;
	head=indextable[val].next;   /*起始指针*/
	printf("   %2d：\t",val);    /*索引地址*/
	while(head!=NULL)
	{  
		printf("[%2d]-",head->val);
		i++;
		if(i%8==7)              /*控制长度*/
			printf("\n\t");
		head=head->next;
	}
	printf("\b \n");            /*清除最后一个"-"符号*/
}
int findnum(int num)     /*哈希查找子程序*/
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
