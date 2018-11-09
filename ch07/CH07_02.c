#include <stdio.h>
#include <stdlib.h>
void select (int *);     /*声明排序法子程序*/
void showdata (int *);   /*声明打印数组子程序*/

int main()
{
	int data[8]={16,25,39,27,12,8,45,63};
	printf("原始数据为：");
	int i;
	for (i=0;i<8;i++)
	 printf("%3d",data[i]);
	printf("\n-------------------------------------");
	select (data);
	printf("排序后数据：");
	for (i=0;i<8;i++)
	 printf("%3d",data[i]);
    printf("\n");
    
	system("pause");
	return 0;
}
void showdata (int data[])
{
	int i;
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");
}

void select (int data[])
{
	int i,j,tmp,k;
	for(i=0;i<7;i++)    /*扫描5次*/
	{   
		for(j=i+1;j<8;j++)  /*从i+1比较起，比较5次*/
		{	
			if(data[i]>data[j])  /*比较第i个和第j个元素*/
			{	
				tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;	
			}
		}
	}
	printf("\n");
}
