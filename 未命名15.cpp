#include<stdio.h>
//��Ĭ�ϲ���ʱֻ��д�ڲ��������ұߣ�����ʱ��ʡ�� �� 
int cp(int i,int w=20)
{
	return (i+w)*2;
}
int main()
{
	int p1=cp(10,20);
	int p2=cp(10);
	printf("%d %d",p1,p2);
	
}
