#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//�����������䡾a��b�����������
//rand����%��b-a��+a; 
int main()
{
	srand(time(0));//time(0)��ʾ��ǰʱ�䣬srand������������ӡ� 
	int input; 
	
	int num=rand()%100;
	while(1)
	{
		printf("������1-100�����֣�");
		scanf("%d",&input);
		fflush(stdin);
		if(input>num) 
		printf("dale");
		else if (input<num)
		printf("xiaole");
		else
		{
		
		printf("dui");
		break;
		}
	
	
	
	}
}
