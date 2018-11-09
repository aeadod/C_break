#include <stdio.h>
#include <stdlib.h>

int main()
{  
	int arr[6][6]={0};
    int i,j,k,tmpi,tmpj;     /*声明矩阵arr*/
	int data[5][2]={{1,2},{2,1},{2,3},{2,4},{4,3}};  /*图形各边的起点值和终点值*/
	
	for (i=0;i<5;i++)       /*读取图形数据*/
		for (j=0;j<5;j++)   /*填入arr矩阵*/
		{  
			tmpi=data[i][0];     /*tmpi为起始顶点*/
			tmpj=data[i][1];     /*tmpj为终止顶点*/
			arr[tmpi][tmpj]=1;   /*有边的点填入1*/
		}
	printf("有向图形矩阵：\n");
	for (i=1;i<5;i++)
	{  
		for (j=1;j<5;j++)
	    printf("[%d] ",arr[i][j]);   /*打印矩阵内容*/
		printf("\n");
	}
	system("pause");
	return 0;
}
