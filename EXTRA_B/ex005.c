#include<stdio.h>
int main(void)
{
    char ch;
    printf("1.80以上,\n2.60~79,\n3.59以下\n");
    printf("请输入分数群组: ");
    scanf("%c",&ch);
    /*switch 条件语句开始*/
    switch(ch)
    {
        /* 此处不加大括号*/
        case '1':
          printf("继续保持!\n");
          break;
        case '2':
          printf("还有进步空间!!\n");
          break;
        case '3':
          printf("请多多努力!!!\n");
          break;
        default:
          printf("error\n");
          break;
    }
    system("pause");
    return 0; 
}
