#include<stdio.h>
int main(void)
{
  int sum=0;
  int number;
  int i; /*����ѭ�����Ʊ���i*/
  printf("����������: ");
  scanf("%d",&number);
  /*����forѭ��,��С����������� */
  printf("\n��С���������������:\n");  
  for(i=1;i<=number; i++)
  {
    sum+=i; //����sumΪi�ĺ� 
    printf("%d",i);
    /*����������ӵ���ʽ */
    if(i<number)printf("+");
    else printf("=");
  }
  printf("%d\n",sum);
  sum=0;
  /*�ݼ�forѭ��,�Ӵ�С������� */
  printf("\n�Ӵ�С�����������:\n");
  for(i=number;i>=1; i--)
  {
    sum+=i; 
    printf("%d",i);
    if(i<=1)printf("=");
    else printf("+");
  }
  printf("%d\n",sum);
  system("pause");
  return 0;
}

