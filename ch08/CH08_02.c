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
		printf("��������Ҽ�ֵ(1-150)������-1������");
		scanf("%d",&val);
		if(val==-1)
			break;
		num=bin_search(data,val);
		if(num==-1)
			printf("##### û���ҵ�[%3d] #####\n",val);
		else
			printf("�ڵ� %2d��λ���ҵ� [%3d]\n",num+1,data[num]);
	}
	printf("�������ݣ�\n");
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
	printf("���ҹ�����......\n");
	while(low <= high && val !=-1)
	{  
		mid=(low+high)/2;
		if(val<data[mid])
		{  
			printf("%d ����λ�� %d[%3d]���м�ֵ %d[%3d]��������\n",val,low+1,data[low],mid+1,data[mid]);
			high=mid-1;	     
		}
		else if(val>data[mid])
		{  
			printf("%d �����м�ֵλ�� %d[%3d] �� %d[%3d]�����Ұ��\n",val,mid+1,data[mid],high+1,data[high]);
			low=mid+1;   	     
		}
		else
			return mid;
	}
	return -1;
}
