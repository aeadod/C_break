#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,j,find,val=0,data[80]={0};
	for (i=0;i<80;i++)
		data[i]=(rand()%150+1);
	while (val!=-1)
	{  
		find=0;
		printf("请输入查找键值(1-150)，输入-1离开：");
		scanf("%d",&val);
		for (i=0;i<80;i++)
		{  
			if(data[i]==val)
			{  
				printf("在第 %3d个位置找到键值 [%3d]\n",i+1,data[i]);
				find++;
			}
		}
		if(find==0 && val !=-1)
			printf("######没有找到 [%3d]######\n",val);
	}
	printf("数据内容：\n");
	for(i=0;i<10;i++)
	{ 
		for(j=0;j<8;j++)
			printf("%2d[%3d]  ",i*8+j+1,data[i*8+j]);
		printf("\n");
	}	
	system("pause");
	return 0;
}
