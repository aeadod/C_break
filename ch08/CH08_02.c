#include<stdio.h>
#include<stdlib.h>

int main()
{  
	int i,j,val=1,num,data[50]={0};
	for (i=0;i<50;i++)
	{  
		data[i]=val;
		val+=(rand()%5+1);
	}
	while (1)
	{  
		num=0;
		printf("请输入查找键值(1-150)，输入-1结束：");
		scanf("%d",&val);
		if(val==-1)
			break;
		num=bin_search(data,val);
		if(num==-1)
			printf("##### 没有找到[%3d] #####\n",val);
		else
			printf("在第 %2d个位置找到 [%3d]\n",num+1,data[num]);
	}
	printf("数据内容：\n");
	for(i=0;i<5;i++)
	{ 
		for(j=0;j<10;j++)
			printf("%3d-%-3d",i*10+j+1,data[i*10+j]);
		printf("\n");
	}
	printf("\n");
	system("pause");
	return 0;
}
int bin_search(int data[50],int val)
{  
	int low,mid,high;
	low=0;
	high=49;
	printf("查找过程中......\n");
	while(low <= high && val !=-1)
	{  
		mid=(low+high)/2;
		if(val<data[mid])
		{  
			printf("%d 介于位置 %d[%3d]和中间值 %d[%3d]，找左半边\n",val,low+1,data[low],mid+1,data[mid]);
			high=mid-1;	     
		}
		else if(val>data[mid])
		{  
			printf("%d 介于中间值位置 %d[%3d] 和 %d[%3d]，找右半边\n",val,mid+1,data[mid],high+1,data[high]);
			low=mid+1;   	     
		}
		else
			return mid;
	}
	return -1;
}
