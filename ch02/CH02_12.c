#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	int A[3][3] = {{1,3,5},{7,9,11},{13,15,17}};/* 二维数组的声明 */ 
	int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};/* 二维数组的声明 */
	int C[3][3] = {0};
	
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	    C[i][j]=A[i][j]+B[i][j];/* 矩阵C=矩阵A+矩阵B */
	
	printf("[矩阵A和矩阵B相加的结果]\n");	/*输出A+B的内容*/
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",C[i][j]);
		printf("\n");
	}
	
	system("pause");
	return 0;
}
