#include <stdio.h>
#include <stdlib.h>

int main()
{
 char arr2[50];
 int i,sum;
 printf("������һ���ַ���:");
   gets(arr2); 

  for (i=0;i<50;i++)
   {
    if (arr2[i]=='\0')
    break; //������û������ַ����Ľ�β���ж�ѭ��
    sum=i;//��¼���ַ�ǰһ���ַ�������
    }
   for (i=sum;i>=0;i--)     //���û�������ַ����������
   printf("%c",arr2[i]); 
   printf("\n");	
   
   system("pause");
   return 0;
 }
