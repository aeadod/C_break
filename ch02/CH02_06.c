#include<stdio.h>
#include<stdlib.h>

int main()
{
	int length;/*���������ַ����ĳ���*/
	char str[30];
	
	printf("�������ַ���:");
	/*�����ַ���*/
	gets(str);
	printf("������ַ���Ϊ:%s\n",str);
	length=0;
	while (str[length]!='\0')
	 length++; 
 	printf("���ַ�����%d���ַ�\n",length);
    
    system("pause");
    return 0;
}
