#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char *str1="Hello World!";
    char* str2=(char*)malloc(sizeof(char)*(strlen(str1)));
    /* ��̬������str1��ͬ��С���ڴ�ռ� */
    
    strcpy(str2,str1);/* ��str1�ַ������Ƶ�str2�ַ��� */ 
    printf("str1=%p str1=%s\n",str1,str1);
    printf("-------------------------------------\n");
    printf("str2=%p str2=%s\n",str2,str2);
    printf("-------------------------------------\n");
    free(str2);/* �ͷ�str2�ڴ�ռ� */ 
    
    system("pause");
    return 0;
}
