#include <stdio.h>
#include <stdlib.h>
#define SIZE 8        /*定义数组大小*/
void inser (int *);     /*声明插入排序法子程序*/
void showdata (int *);  /*声明打印数组子程序*/

int main()
{ 
	int data[SIZE]={16,25,39,27,12,8,45,63};
	
	printf("原始数组是：");
	showdata(data);
	printf("\n");
	inser(data);
	printf("排序后数组是：");
	showdata(data);
	
	
    system("pause");
	return 0;
}

void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);   /*打印数组数据*/
	printf("\n");
}
void inser(int data[])
{  
	int i;     /*i为扫描次数*/
	int no;     /*以j来定位比较的元素*/
	int tmp;   /*tmp用来暂存数据*/
	for (i=1;i<SIZE;i++)  /*扫描循环次数为SIZE-1*/
	{  
	 tmp=data[i];
     no=i-1;
     while (no>=0 && tmp<data[no]) /*如果第二个元素小于第一个元素*/
	{							 
			data[no+1]=data[no];		/*就把所有元素往后推一个位置*/		
			no--;
	} 
	 data[no+1]=tmp;              /*最小的元素放到第一个元素*/	
	}
}
