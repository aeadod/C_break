#include <stdio.h>
#include <stdlib.h>

int main()
{  
	int arr[6][6]={0},i,j,k,tmpi,tmpj;            /*声明矩阵arr*/
	int data[14][2]={{1,2},{2,1},{1,5},{5,1}, 	/*图各边的起点值和终点值*/
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3}};
	for (i=0;i<14;i++)         /*读取图的数据*/
		for (j=0;j<6;j++)      /*填入arr矩阵*/
			for (k=0;k<6;k++)
			{  
				tmpi=data[i][0];    /*tmpi为起始顶点*/
				tmpj=data[i][1];    /*tmpj为终止顶点*/
				arr[tmpi][tmpj]=1;  /*有边的点填入1*/
			}
	printf("无向图形矩阵：\n");
	for (i=1;i<6;i++)
	{  
		for (j=1;j<6;j++)
	    printf("[%d] ",arr[i][j]);  /*打印矩阵内容*/
		printf("\n");
	}
	system("pause");
	return 0;
}
