#include<stdio.h>
int main()
{
	printf("�����������\n");
	printf("�����������ָ�����ˣ�ֻ�ܰ�һ������Ҫ���ĸ���\n");
	printf("1:��Ĵָ2:ʳָ3:��ָ4:����ָ5:Сָ\n");
	
	int c=0;
	while(1)
	{
		printf("��ѡ��");
		scanf("%d",&c);
		fflush(stdin);//���scanf�Ļ���������ֹ����С��ʱ������ѭ���� 
		if(c==1)
		printf("���˰���һ��");
		else if(c==2)
		printf("�㰮����һ��");
		else if(c==3)
		printf("�㰮�ܶ���");
		else if(c==4)
		printf("�㰮�Լ�");
		else if(c==5)
	
		printf("�ܶ��˰���"); 
		else if(c<=0)
		break;
		else 
		printf("�������");	
	
	 } 
}
