#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *name[4] = { "Justinian", "Momo", "Becky", "Bush" };/* һάָ������ */ 
    char name1[4][10] = { "Justinian", "Momo", "Becky", "Bush" };/* ��ά�ַ�������  */ 
    int i;
    printf("---------- һάָ������洢��ʽ -------------- \n");
    for ( i = 0; i < 4; i++ )
    {
        printf( "name[%d] = \"%s\"\t",i,name[i] );
        printf( "��ռ��ַ��%p \n", name[i]); /* ��ӡ��name[i]��ռ��ַ */   
    }
    printf("------------ ��ά�ַ�������洢��ʽ-------------- \n");
    for ( i = 0; i < 4; i++ )
    {
        printf( "name1[%d] = \"%s\"\t",i,name1[i] );
        printf( "��ռ��ַ��%p \n",&name1[i][0]);/* ��ӡ��name1[i]��ռ��ַ */ 
     }    
    system("pause");
    return 0;
}
