#include <stdio.h>
#include <stdlib.h>

int main()
{  
	int arr[6][6]={0};
    int i,j,k,tmpi,tmpj;     /*��������arr*/
	int data[5][2]={{1,2},{2,1},{2,3},{2,4},{4,3}};  /*ͼ�θ��ߵ����ֵ���յ�ֵ*/
	
	for (i=0;i<5;i++)       /*��ȡͼ������*/
		for (j=0;j<5;j++)   /*����arr����*/
		{  
			tmpi=data[i][0];     /*tmpiΪ��ʼ����*/
			tmpj=data[i][1];     /*tmpjΪ��ֹ����*/
			arr[tmpi][tmpj]=1;   /*�бߵĵ�����1*/
		}
	printf("����ͼ�ξ���\n");
	for (i=1;i<5;i++)
	{  
		for (j=1;j<5;j++)
	    printf("[%d] ",arr[i][j]);   /*��ӡ��������*/
		printf("\n");
	}
	system("pause");
	return 0;
}
