#include <stdio.h>
#include <stdlib.h>

int main()
{  
	int arr[6][6]={0},i,j,k,tmpi,tmpj;            /*��������arr*/
	int data[14][2]={{1,2},{2,1},{1,5},{5,1}, 	/*ͼ���ߵ����ֵ���յ�ֵ*/
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3}};
	for (i=0;i<14;i++)         /*��ȡͼ������*/
		for (j=0;j<6;j++)      /*����arr����*/
			for (k=0;k<6;k++)
			{  
				tmpi=data[i][0];    /*tmpiΪ��ʼ����*/
				tmpj=data[i][1];    /*tmpjΪ��ֹ����*/
				arr[tmpi][tmpj]=1;  /*�бߵĵ�����1*/
			}
	printf("����ͼ�ξ���\n");
	for (i=1;i<6;i++)
	{  
		for (j=1;j<6;j++)
	    printf("[%d] ",arr[i][j]);  /*��ӡ��������*/
		printf("\n");
	}
	system("pause");
	return 0;
}
