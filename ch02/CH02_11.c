#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arrB[4][4],i,j;
    int arrA[4][4]={ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	printf("[请输入矩阵内容]\n");
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",arrA[i][j]);
		}
		printf("\n");
	}
	/*进行矩阵转置的操作*/
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			arrB[i][j]=arrA[j][i];

	printf("[转置矩阵内容为]\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",arrB[i][j]);
		}
		printf("\n");/* 打印转置矩阵内容 */ 
	}
	system("pause");
}
