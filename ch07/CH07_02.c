#include <stdio.h>
#include <stdlib.h>
void select (int *);     /*���������ӳ���*/
void showdata (int *);   /*������ӡ�����ӳ���*/

int main()
{
	int data[8]={16,25,39,27,12,8,45,63};
	printf("ԭʼ����Ϊ��");
	int i;
	for (i=0;i<8;i++)
	 printf("%3d",data[i]);
	printf("\n-------------------------------------");
	select (data);
	printf("��������ݣ�");
	for (i=0;i<8;i++)
	 printf("%3d",data[i]);
    printf("\n");
    
	system("pause");
	return 0;
}
void showdata (int data[])
{
	int i;
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");
}

void select (int data[])
{
	int i,j,tmp,k;
	for(i=0;i<7;i++)    /*ɨ��5��*/
	{   
		for(j=i+1;j<8;j++)  /*��i+1�Ƚ��𣬱Ƚ�5��*/
		{	
			if(data[i]>data[j])  /*�Ƚϵ�i���͵�j��Ԫ��*/
			{	
				tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;	
			}
		}
	}
	printf("\n");
}
