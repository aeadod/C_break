#include <stdio.h>
#include <stdlib.h>

void Btree_create(int *btree,int *data,int length)
{
	int i,level;
	
    for(i=1;i<length;i++) /*��ԭʼ�����е�ֵ��һ�Ա�*/
	{  
		for(level=1;btree[level]!=0;)/*�Ƚ������������ڵ�ֵ*/
		{  
			if(data[i]>btree[level]) /*��������ڵ�ֵ���������������������Ƚ�*/
				level=level*2+1;
			else /*��������ڵ�ֵС�ڻ���������������������Ƚ�*/
				level=level*2;
		}        /*��������ڵ��ֵ��Ϊ0�������������ڵ�ֵ�Ƚ�һ��*/
		btree[level]=data[i]; /*������ֵ���������*/
	}
}
int main()
{  
	int i,length=9;
	int data[]={0,6,3,5,4,7,8,9,2};/*ԭʼ����*/
	int btree[16]={0}; /*��Ŷ���������*/
	printf("ԭʼ�������ݣ�\n");	
	for(i=0;i<length;i++)
		printf("[%2d] ",data[i]);
	printf("\n");
	Btree_create(btree,data,9);
	printf("���������ݣ�\n");
	for (i=1;i<16;i++)
		printf("[%2d] ",btree[i]);
	printf("\n");
	system("pause");
	return 0;
}
