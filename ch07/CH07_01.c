#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,tmp;
	int data[8]={16,25,39,27,12,8,45,63};	/* 原始数据 */
	printf("冒泡排序法：\n原始数据为：");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");

	for (i=7;i>0;i--)		/* 扫描次数 */
	{
		for (j=0;j<i;j++)/*比较、交换次数*/
		{
			if (data[j]>data[j+1])	/* 比较相邻两数，如第一个数较大则交换 */
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
		printf("第 %d 次排序后的结果是：",6-i); /*把各次扫描后的结果输出*/
		for (j=0;j<8;j++)
			printf("%3d",data[j]);
		printf("\n");
	}
	printf("排序后结果为：");
	for (i=0;i<8;i++)
		printf("%3d",data[i]);
	printf("\n");
	
    system("pause");
	return 0;
}
