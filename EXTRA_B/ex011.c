#include<stdio.h>
/*����ȡַ������ĺ���ԭ������*/
void fun(int*, int*);
int main(void)
{	
	int a,b;
 	a=10;
    b=15;
    printf("������:\na=%d,\tb=%d\n",a,b);
    printf("a�ĵ�ַ:%d, b�ĵ�ַ:%d\n",&a,&b);
    /*�Ա��������&ȡַ�����*/	
	fun(&a,&b);
	printf("==========================\n");
	printf("���ú�����: \na=%d,\tb=%d\n",a,b);
	system("pause");
	return 0;	
}
void fun(int *a, int *b)
{
	printf("==========================\n");
 	printf("������:\n");
 	/*��ʱ��*a��*b������ǵ�ַ�ϵ���ֵ*/
	printf("�����Ա���:a=%d,\tb=%d\n",*a,*b);
	/*���������a��b�ĵ�ַ*/
	printf("a�ĵ�ַ:%d, b�ĵ�ַ:%d\n",a,b);
	*a=20;
	*b=30;	
	printf("�����ֵ��:a=%d, b=%d\n",*a,*b);
}
