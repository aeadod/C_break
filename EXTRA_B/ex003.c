#include <stdio.h>
int main(void)
{
    int iVal;
    printf("请输入8进制数值:");
    scanf("%o",&iVal);
    printf("您所输入8进制数值，其10进制值为:%d\n",iVal);
    printf("\n");

    printf("请输入10进制数值:");
    scanf("%d",&iVal);
    printf("您所输入10进制数值，其8进制值为:%o\n",iVal);
    printf("\n");

    printf("请输入16进制数值:");
    scanf("%x",&iVal);
    printf("您所输入16进制数值，其10进制值为:%d\n",iVal);
    printf("\n");

    printf("请输入10进制数值:");
    scanf("%d",&iVal);
    printf("您所输入10进制数值，其16进制值为:%x\n",iVal);
    printf("\n");    
    system("pause");
    return 0;
}

