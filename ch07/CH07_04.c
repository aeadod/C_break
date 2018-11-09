#include <stdio.h>
#include <stdlib.h>
#define SIZE 8           

void shell (int *,int);   /*声明排序法子程序*/
void showdata (int *);   /*声明打印数组子程序*/

int main(void)
{ 
	int data[SIZE]={16,25,39,27,12,8,45,63};
	printf("原始数组是：     ");	
	showdata (data);
	printf("-----------------------------------------\n");
	shell(data,SIZE);
	
    system("pause");
	return 0;
}

void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);
	printf("\n");
}
void shell(int data[],int size)
{  
	int i;        /*i为扫描次数*/
	int j;        /*以j来定位比较的元素*/
	int k=1;      /*k打印计数*/
	int tmp;      /*tmp用来暂存数据*/
	int jmp;      /*设定间距位移量*/
	jmp=size/2;
	while (jmp != 0)
	{  
		for (i=jmp ;i<size ;i++)
		{  
			tmp=data[i];
			j=i-jmp;
			while(tmp<data[j] && j>=0)  /*插入排序法*/
			{  
				data[j+jmp] = data[j];
				j=j-jmp;
			}	
			data[jmp+j]=tmp;
		}
		printf("第 %d 次排序过程：",k++);
		showdata (data);
		printf("-----------------------------------------\n");
		jmp=jmp/2;    /*控制循环数*/
	}
}
