#include <stdio.h>
int main(void)
{
    int Val=123;
    printf("各种格式化字符的输出\n");
    printf("  Val=%d\n",Val);
    printf("%%iVal=%i\n",Val);
    printf("%%oVal=%o\n",Val);
    printf("%%uVal=%u\n",Val);
    printf("%%xVal=%x\n",Val); 
    system("pause");     
    return 0;
}
