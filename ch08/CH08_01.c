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
		printf("��������Ҽ�ֵ(1-150)������-1�뿪��");
		scanf("%d",&val);
		for (i=0;i<80;i++)
		{  
			if(data[i]==val)
			{  
				printf("�ڵ� %3d��λ���ҵ���ֵ [%3d]\n",i+1,data[i]);
				find++;
			}
		}
		if(find==0 && val !=-1)
			printf("######û���ҵ� [%3d]######\n",val);
	}
	printf("�������ݣ�\n");
	for(i=0;i<10;i++)
	{ 
		for(j=0;j<8;j++)
			printf("%2d[%3d]  ",i*8+j+1,data[i*8+j]);
		printf("\n");
	}	
	system("pause");
	return 0;
}
