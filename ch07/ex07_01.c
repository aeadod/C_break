#include <stdio.h>
#include <stdlib.h>

void bubble (int *);   
void showdata (int *); 
int main()
{
	int data[8]={14,6,12,27,8,9,50,21};	  /*ԭʼ����*/
	int i;
	printf("ԭʼ����Ϊ��");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n-------------------------------------\n");
	bubble (data);
	printf("\n���������");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	
	printf("\n");
	system("pause");
	return 0;
}

void bubble (int data[])
{
	int i,j,tmp,flag;
	for(i=7;i>=0;i--)
	{
		flag=0;           /*flag�����ж��Ƿ�ִ���˽����Ĳ���*/
		for (j=0;j<i;j++)
		{
			if (data[j+1]<data[j])
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;    /*���ִ�й���������flag��Ϊ0*/
			}
		}
		if (flag==0)
			break;
		/*
		��ִ����һ��ɨ����ж��Ƿ�ִ�й��������������û�н���������
		����ʾ��ʱ������������򣬹ʿ�ֱ������ѭ��
		*/	  
        printf("�� %d ������",8-i);
        for (j=0;j<8;j++)
        printf("%3d",data[j]);
        printf("\n");		      
	}
}
