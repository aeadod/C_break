/*
[示范]:下三角矩阵 
*/
#include <stdio.h>
#define ARRAY_SIZE 5  /* 矩阵的维数大小 */
int getValue(int ,int);
int A[ARRAY_SIZE][ARRAY_SIZE]={  /*下三角矩阵的内容 */
                			{76, 0, 0, 0, 0}, 
               			 	{54, 51, 0, 0, 0}, 
              				{23, 8, 26, 0, 0}, 
                			{43, 35, 28, 18, 0}, 
                			{12, 9, 14, 35, 46}};  
/* 一维数组的声明 */
int B[ARRAY_SIZE*(1+ARRAY_SIZE)/2];  
int main()
{
    int i=0,j=0;
    int index;    
		printf("==========================================\n");
		printf("下三角形矩阵：\n");
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = 0 ; j < ARRAY_SIZE ; j++ ) 
		        printf("\t%d",A[i][j]);
		    printf("\n");    
		}
		/* 将左下三角矩阵压缩为一维数组 */
		index=0;
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = 0 ; j < ARRAY_SIZE ; j++ ) 
			{
                if(A[i][j]!=0) B[index++]=A[i][j];
            }
        }
		printf("==========================================\n");
		printf("以一维的方式表示：\n");
		printf("\t[");
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = i ; j < ARRAY_SIZE ; j++ ) 
		        printf(" %d",getValue(i,j));
		}
		printf(" ]");
		printf("\n");    
		system("pause");
}
int getValue(int i, int j) {
        int index = ARRAY_SIZE*i-i*(i+1)/2+j;
        return B[index];
}
