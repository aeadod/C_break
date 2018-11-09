#include <stdio.h>
#include <stdlib.h>

void bubble (int *);   
void showdata (int *); 
int main()
{
	int data[8]={14,6,12,27,8,9,50,21};	  /*原始数据*/
	int i;
	printf("原始数据为：");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n-------------------------------------\n");
	bubble (data);
	printf("\n排序后结果：");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	
	printf("\n");
	system("pause");
	return 0;
}

void bubble (int data[])
{
	int i,j,tmp,flag;
	for(i=7;i>=0;i--)
	{
		flag=0;           /*flag用来判断是否执行了交换的操作*/
		for (j=0;j<i;j++)
		{
			if (data[j+1]<data[j])
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;    /*如果执行过交换，则flag不为0*/
			}
		}
		if (flag==0)
			break;
		/*
		当执行完一次扫描就判断是否执行过交换操作，如果没有交换过数据
		，表示此时数组已完成排序，故可直接跳出循环
		*/	  
        printf("第 %d 次排序：",8-i);
        for (j=0;j<8;j++)
        printf("%3d",data[j]);
        printf("\n");		      
	}
}
