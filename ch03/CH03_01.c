#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char *str1="Hello World!";
    char* str2=(char*)malloc(sizeof(char)*(strlen(str1)));
    /* 动态分配与str1相同大小的内存空间 */
    
    strcpy(str2,str1);/* 将str1字符串复制到str2字符串 */ 
    printf("str1=%p str1=%s\n",str1,str1);
    printf("-------------------------------------\n");
    printf("str2=%p str2=%s\n",str2,str2);
    printf("-------------------------------------\n");
    free(str2);/* 释放str2内存空间 */ 
    
    system("pause");
    return 0;
}
