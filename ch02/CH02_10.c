#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *name[4] = { "Justinian", "Momo", "Becky", "Bush" };/* 一维指针数组 */ 
    char name1[4][10] = { "Justinian", "Momo", "Becky", "Bush" };/* 二维字符串数组  */ 
    int i;
    printf("---------- 一维指针数组存储方式 -------------- \n");
    for ( i = 0; i < 4; i++ )
    {
        printf( "name[%d] = \"%s\"\t",i,name[i] );
        printf( "所占地址：%p \n", name[i]); /* 打印出name[i]所占地址 */   
    }
    printf("------------ 二维字符串数组存储方式-------------- \n");
    for ( i = 0; i < 4; i++ )
    {
        printf( "name1[%d] = \"%s\"\t",i,name1[i] );
        printf( "所占地址：%p \n",&name1[i][0]);/* 打印出name1[i]所占地址 */ 
     }    
    system("pause");
    return 0;
}
