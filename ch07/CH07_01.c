#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,tmp;
	int data[8]={16,25,39,27,12,8,45,63};	/* ԭʼ���� */
	printf("ð�����򷨣�\nԭʼ����Ϊ��");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");

	for (i=7;i>0;i--)		/* ɨ����� */
	{
		for (j=0;j<i;j++)/*�Ƚϡ���������*/
		{
			if (data[j]>data[j+1])	/* �Ƚ��������������һ�����ϴ��򽻻� */
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
		printf("�� %d �������Ľ���ǣ�",6-i); /*�Ѹ���ɨ���Ľ�����*/
		for (j=0;j<8;j++)
			printf("%3d",data[j]);
		printf("\n");
	}
	printf("�������Ϊ��");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");
	
    system("pause");
	return 0;
}
