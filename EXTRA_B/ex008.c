#include<stdio.h>
int main(void)
{
  int number;
  int sum=0;
  /*do whileѭ����ʼ*/ 
  do
  {
    printf("����0Ϊ��������,����������: ");
    scanf("%d",&number);
    sum+=number;
    printf("Ŀǰ�ۼӵĽ��Ϊ: %d\n",sum);
  }while(number!=0);/*do whileѭ������*/
  system("pause");
  return 0;
}
