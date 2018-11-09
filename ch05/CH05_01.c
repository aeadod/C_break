#include <stdio.h>
#include <stdlib.h>

void Btree_create(int *btree,int *data,int length)
{
	int i,level;
	
    for(i=1;i<length;i++) /*把原始数组中的值逐一对比*/
	{  
		for(level=1;btree[level]!=0;)/*比较树根和数组内的值*/
		{  
			if(data[i]>btree[level]) /*如果数组内的值大于树根，则往右子树比较*/
				level=level*2+1;
			else /*如果数组内的值小于或等于树根，则往左子树比较*/
				level=level*2;
		}        /*如果子树节点的值不为0，则再与数组内的值比较一次*/
		btree[level]=data[i]; /*把数组值放入二叉树*/
	}
}
int main()
{  
	int i,length=9;
	int data[]={0,6,3,5,4,7,8,9,2};/*原始数组*/
	int btree[16]={0}; /*存放二叉树数组*/
	printf("原始数组内容：\n");	
	for(i=0;i<length;i++)
		printf("[%2d] ",data[i]);
	printf("\n");
	Btree_create(btree,data,9);
	printf("二叉树内容：\n");
	for (i=1;i<16;i++)
		printf("[%2d] ",btree[i]);
	printf("\n");
	system("pause");
	return 0;
}
