#include<stdio.h>
/*����ԭ������*/
void fun(int, int);
int main(void)
{	
	int a,b;
 	a=10;
    b=15;
    /*����������е�a,bֵ���ַ*/
    printf("������:\na=%d,\tb=%d\n",a,b);
    printf("a�ĵ�ַ:%d, b�ĵ�ַ:%d\n",&a,&b);	
	/*���ú���*/
    fun(a,b);
    /*�ָ���*/
	printf("==========================\n");
 	/*������ú������a,bֵ*/
  	printf("���ú�����: \na=%d,\tb=%d\n",a,b);
  	system("pause");
 	return 0;	
}
void fun(int a, int b)
{
	printf("==========================\n");
 	printf("������:\n");
 	printf("�����Ա���:a=%d, b=%d\n",a,b);
 	printf("a�ĵ�ַ:%d, b�ĵ�ַ:%d\n",&a,&b);
 	/*���躯���ڵ�a,bֵ*/
	a=20;
	b=30;
	printf("�����ֵ��:a=%d, b=%d\n",a,b);
}
