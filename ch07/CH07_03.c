#include <stdio.h>
#include <stdlib.h>
#define SIZE 8        /*���������С*/
void inser (int *);     /*�������������ӳ���*/
void showdata (int *);  /*������ӡ�����ӳ���*/

int main()
{ 
	int data[SIZE]={16,25,39,27,12,8,45,63};
	
	printf("ԭʼ�����ǣ�");
	showdata(data);
	printf("\n");
	inser(data);
	printf("����������ǣ�");
	showdata(data);
	
	
    system("pause");
	return 0;
}

void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);   /*��ӡ��������*/
	printf("\n");
}
void inser(int data[])
{  
	int i;     /*iΪɨ�����*/
	int no;     /*��j����λ�Ƚϵ�Ԫ��*/
	int tmp;   /*tmp�����ݴ�����*/
	for (i=1;i<SIZE;i++)  /*ɨ��ѭ������ΪSIZE-1*/
	{  
	 tmp=data[i];
     no=i-1;
     while (no>=0 && tmp<data[no]) /*����ڶ���Ԫ��С�ڵ�һ��Ԫ��*/
	{							 
			data[no+1]=data[no];		/*�Ͱ�����Ԫ��������һ��λ��*/		
			no--;
	} 
	 data[no+1]=tmp;              /*��С��Ԫ�طŵ���һ��Ԫ��*/	
	}
}
