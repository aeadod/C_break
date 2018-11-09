#include<stdio.h>
#include<stdlib.h>

int main()
{
	int length;/*用作计算字符串的长度*/
	char str[30];
	
	printf("请输入字符串:");
	/*输入字符串*/
	gets(str);
	printf("输入的字符串为:%s\n",str);
	length=0;
	while (str[length]!='\0')
	 length++; 
 	printf("此字符串有%d个字符\n",length);
    
    system("pause");
    return 0;
}
