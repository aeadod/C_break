#include <stdio.h>
#include <stdlib.h>
#define SIZE   7  
#define INFINITE  99999 
#define NUMBER 6

int Graph_Matrix[SIZE][SIZE];/* 图的数组 */
int distance[SIZE][SIZE];/* 路径长度数组 */

/* 建立图 */
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;/* 边的起点 */
   int End_Point; /* 边的终点 */
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if (i==j)
            Graph_Matrix[i][j] = 0; /* 对角线设为0 */
         else
            Graph_Matrix[i][j] = INFINITE;  
   /* 存入图的边 */  
   i=0;
   while(i<SIZE)
   {
      Start_Point = Path_Cost[i*3]; 
      End_Point = Path_Cost[i*3+1]; 
      Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
      i++;
   }
}
/* 输出图形 */
 
void shortestPath(int vertex_total)
{       
   int i,j,k;
   /* 图的长度数组初始化  */
   for (i=1;i<=vertex_total;i++ )
      for (j=i;j<=vertex_total;j++ )
         {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
         }
     /* 利用Floyd算法找出所有顶点两两之间的最短距离 */       
   for (k=1;k<=vertex_total;k++ ) 
      for (i=1;i<=vertex_total;i++ )
         for (j=1;j<=vertex_total;j++ )
            if (distance[i][k]+distance[k][j]<distance[i][j])
                distance[i][j] = distance[i][k] + distance[k][j];   
}
/* 主程序 */
int main() 
{
   int Path_Cost[7][3] = { {1, 2,20}, 
                      {2, 3, 30},
                      {2, 4, 25},
                      {3, 5, 28},
                      {4, 5, 32},
                      {4, 6, 95},
                      {5, 6, 67} }; 
   int i,j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   printf("===========================================\n");
   printf("      所有顶点两两之间的最短距离: \n");
   printf("===========================================\n");
   shortestPath(NUMBER); /* 计算所有顶点间的最短路径 */
   /*求得两两顶点间的最短路径长度数组后，将其输出*/
   printf("       顶点1 顶点2 顶点3 顶点4 顶点5 顶点6\n");
      for ( i = 1; i <= NUMBER; i++ )
      {
         printf("顶点%d",i);
         for ( j = 1; j <= NUMBER; j++ )
         {
            printf("%5d ",distance[i][j]);
         }
         printf("\n");
      }
   printf("===========================================\n");
   printf("\n");
   system("PAUSE");
   return 0; 
}

