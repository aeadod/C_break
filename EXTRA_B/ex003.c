#include <stdio.h>
int main(void)
{
    int iVal;
    printf("������8������ֵ:");
    scanf("%o",&iVal);
    printf("��������8������ֵ����10����ֵΪ:%d\n",iVal);
    printf("\n");

    printf("������10������ֵ:");
    scanf("%d",&iVal);
    printf("��������10������ֵ����8����ֵΪ:%o\n",iVal);
    printf("\n");

    printf("������16������ֵ:");
    scanf("%x",&iVal);
    printf("��������16������ֵ����10����ֵΪ:%d\n",iVal);
    printf("\n");

    printf("������10������ֵ:");
    scanf("%d",&iVal);
    printf("��������10������ֵ����16����ֵΪ:%x\n",iVal);
    printf("\n");    
    system("pause");
    return 0;
}

