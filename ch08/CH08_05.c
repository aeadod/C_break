#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INDEXBOX 10    /*��ϣ�����Ԫ��*/
#define MAXNUM 7       /*������ݸ���*/

int main()
{  
	int i,index[INDEXBOX],data[MAXNUM];
	srand((unsigned)time(NULL));     /*��ʱ���ʼ�������*/
	printf("ԭʼ����ֵ��\n");
	for(i=0;i<MAXNUM;i++)       /*��ʼ����ֵ*/
		data[i]=rand()%20+1;
	for(i=0;i<INDEXBOX;i++)     /*�����ϣ��*/
		index[i]=-1;
	print_data(data,MAXNUM);    /*��ӡ��ʼ����*/
	printf("��ϣ�����ݣ�\n");
	for(i=0;i<MAXNUM;i++)       /*������ϣ��*/
	{  
		creat_table(data[i],index);
		printf("  %2d =>",data[i]);  /*��ӡ��һԪ�صĹ�ϣ��λ��*/
		print_data(index,INDEXBOX);
	}
	printf("��ɹ�ϣ��\n");     
	print_data(index,INDEXBOX);  /*��ӡ�����ɽ��*/
	system("pause");
	return 0;
}
int print_data(int *data,int max)  /*��ӡ�����ӳ���*/
{  
	int i;
	printf("\t");
	for(i=0;i<max;i++)
		printf("[%2d] ",data[i]);
	printf("\n");
}
int creat_table(int num,int *index)  /*������ϣ���ӳ���*/
{  
	int tmp;
	tmp=num%INDEXBOX;    /*��ϣ����=����%INDEXBOX*/
	while(1)
	{  
		if(index[tmp]==-1)      /*������ݶ�Ӧ��λ���ǿյ�*/
		{  
			index[tmp]=num;     /*��ֱ�Ӵ�������*/
			break;
		}
		else
			tmp=(tmp+1)%INDEXBOX;    /*����������λ�ô��*/
	}
}
