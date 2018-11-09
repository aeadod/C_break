#include<stdio.h>
#include<string.h>
int main(void)
{
	int i;
	char choice;
	/*声明字符串数组并初始化*/
 	char newspaper[5][20]={{"1.水果日报"},
 							{"2.联合日报"},
        					{"3.自由报"},
             				{"4.中国日报"},
                 			{"5.不需要"}};
	/*字符串数组的输出*/
	for(i=0; i<5; i++)
	{
		printf("%s  ",newspaper[i]);
	}
 	printf("请输入选择:");
 	choice=getche();
 	printf("\n");
 	choice=choice-'0';
 	/*输入的判断*/
 	if(choice>=0 && choice<4)
 	{
  		printf("%s",newspaper[choice-1]);
    	printf("\n谢谢您的订购!!!\n");
    }	
    else if(choice==5)
  		printf("\n感谢您的参考!!!\n");
  	else
  		printf("输入错误\n");
	system("pause");
	return 0;
}
