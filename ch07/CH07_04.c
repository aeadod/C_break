#include <stdio.h>
#include <stdlib.h>
#define SIZE 8           

void shell (int *,int);   /*���������ӳ���*/
void showdata (int *);   /*������ӡ�����ӳ���*/

int main(void)
{ 
	int data[SIZE]={16,25,39,27,12,8,45,63};
	printf("ԭʼ�����ǣ�     ");	
	showdata (data);
	printf("-----------------------------------------\n");
	shell(data,SIZE);
	
    system("pause");
	return 0;
}

void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);
	printf("\n");
}
void shell(int data[],int size)
{  
	int i;        /*iΪɨ�����*/
	int j;        /*��j����λ�Ƚϵ�Ԫ��*/
	int k=1;      /*k��ӡ����*/
	int tmp;      /*tmp�����ݴ�����*/
	int jmp;      /*�趨���λ����*/
	jmp=size/2;
	while (jmp != 0)
	{  
		for (i=jmp ;i<size ;i++)
		{  
			tmp=data[i];
			j=i-jmp;
			while(tmp<data[j] && j>=0)  /*��������*/
			{  
				data[j+jmp] = data[j];
				j=j-jmp;
			}	
			data[jmp+j]=tmp;
		}
		printf("�� %d ��������̣�",k++);
		showdata (data);
		printf("-----------------------------------------\n");
		jmp=jmp/2;    /*����ѭ����*/
	}
}
