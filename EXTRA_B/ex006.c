#include<stdio.h>
int main(void)
{
  int sum=0;
  int number;
  int i; /*声明循环控制变量i*/
  printf("请输入整数: ");
  scanf("%d",&number);
  /*递增for循环,从小到大输出数字 */
  printf("\n从小到大排列输出数字:\n");  
  for(i=1;i<=number; i++)
  {
    sum+=i; //设置sum为i的和 
    printf("%d",i);
    /*设置输出连加的算式 */
    if(i<number)printf("+");
    else printf("=");
  }
  printf("%d\n",sum);
  sum=0;
  /*递减for循环,从大到小输出数字 */
  printf("\n从大到小排列输出数字:\n");
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

