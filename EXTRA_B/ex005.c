#include<stdio.h>
int main(void)
{
    char ch;
    printf("1.80����,\n2.60~79,\n3.59����\n");
    printf("���������Ⱥ��: ");
    scanf("%c",&ch);
    /*switch ������俪ʼ*/
    switch(ch)
    {
        /* �˴����Ӵ�����*/
        case '1':
          printf("��������!\n");
          break;
        case '2':
          printf("���н����ռ�!!\n");
          break;
        case '3':
          printf("����Ŭ��!!!\n");
          break;
        default:
          printf("error\n");
          break;
    }
    system("pause");
    return 0; 
}
