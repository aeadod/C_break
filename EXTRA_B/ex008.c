#include<stdio.h>
int main(void)
{
  int number;
  int sum=0;
  /*do while循环开始*/ 
  do
  {
    printf("数字0为结束程序,请输入数字: ");
    scanf("%d",&number);
    sum+=number;
    printf("目前累加的结果为: %d\n",sum);
  }while(number!=0);/*do while循环结束*/
  system("pause");
  return 0;
}
