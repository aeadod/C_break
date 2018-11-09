#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INDEXBOX 10    /*哈希表最大元素*/
#define MAXNUM 7       /*最大数据个数*/

int main()
{  
	int i,index[INDEXBOX],data[MAXNUM];
	srand((unsigned)time(NULL));     /*按时间初始化随机数*/
	printf("原始数组值：\n");
	for(i=0;i<MAXNUM;i++)       /*起始数据值*/
		data[i]=rand()%20+1;
	for(i=0;i<INDEXBOX;i++)     /*清除哈希表*/
		index[i]=-1;
	print_data(data,MAXNUM);    /*打印起始数据*/
	printf("哈希表内容：\n");
	for(i=0;i<MAXNUM;i++)       /*建立哈希表*/
	{  
		creat_table(data[i],index);
		printf("  %2d =>",data[i]);  /*打印单一元素的哈希表位置*/
		print_data(index,INDEXBOX);
	}
	printf("完成哈希表：\n");     
	print_data(index,INDEXBOX);  /*打印最后完成结果*/
	system("pause");
	return 0;
}
int print_data(int *data,int max)  /*打印数组子程序*/
{  
	int i;
	printf("\t");
	for(i=0;i<max;i++)
		printf("[%2d] ",data[i]);
	printf("\n");
}
int creat_table(int num,int *index)  /*建立哈希表子程序*/
{  
	int tmp;
	tmp=num%INDEXBOX;    /*哈希函数=数据%INDEXBOX*/
	while(1)
	{  
		if(index[tmp]==-1)      /*如果数据对应的位置是空的*/
		{  
			index[tmp]=num;     /*则直接存入数据*/
			break;
		}
		else
			tmp=(tmp+1)%INDEXBOX;    /*否则往后找位置存放*/
	}
}
