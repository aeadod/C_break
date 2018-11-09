#include <stdio.h>
#include <stdlib.h>
#define SIZE   7  
#define NUMBER 6
#define INFINITE  99999/* 无穷大 */ 

int Graph_Matrix[SIZE][SIZE];/* 图的数组 */
int distance[SIZE];/* 路径长度数组 */
/* 建立图 */ 
void BuildGraph_Matrix(int *Path_Cost);
void shortestPath(int vertex1, int vertex_total);

/* 主程序 */
int main() 
{
   int Path_Cost[8][3] = { {1, 2, 29}, 
                      {2, 3, 30},
                      {2, 4, 35},
                      {3, 5, 28},
                      {3, 6, 87},
                      {4, 5, 42},
                      {4, 6, 75},
                      {5, 6, 97} }; 
   int j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   shortestPath(1,NUMBER); /* 搜索最短路径 */
   printf("-----------------------------------\n");
   printf("顶点1到各顶点最短距离的最终结果\n");
   printf("-----------------------------------\n");
   for (j=1;j<SIZE;j++) 
      printf("顶点 1到顶点%2d的最短距离=%3d\n",j,distance[j]);
   printf("-----------------------------------\n");
   printf("\n");
  
   system("PAUSE");
   return 0; 
}
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;/* 边的起点 */
   int End_Point; /* 边的终点 */
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if ( i == j )
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

/* 单点对全部顶点的最短距离 */ 
void shortestPath(int vertex1, int vertex_total)
{       
   int shortest_vertex = 1; /*记录最短距离的顶点*/
   int shortest_distance;   /*记录最短距离*/
   int goal[SIZE]; /*用来记录该顶点是否被选取*/ 
   int i,j;
   for ( i = 1; i <= vertex_total; i++ )
   { 
      goal[i] = 0;    
      distance[i] = Graph_Matrix[vertex1][i]; 
   }
   goal[vertex1] = 1;  
   distance[vertex1] = 0;  
   printf("\n");
   
   for (i=1; i<=vertex_total-1; i++ ) 
   {      
      shortest_distance = INFINITE;      
      /* 搜索最短距离的顶点 */
      for (j=1;j<=vertex_total;j++ )
         if (goal[j]==0&&shortest_distance>distance[j])
         {
            shortest_distance=distance[j];                                              
            shortest_vertex=j;              
         }
      goal[shortest_vertex] = 1;   
      /* 计算开始顶点到各顶点的最短距离 */
      for (j=1;j<=vertex_total;j++ )
      {
         if ( goal[j] == 0 && 
         distance[shortest_vertex]+Graph_Matrix[shortest_vertex][j]
         <distance[j])
         {
           distance[j]=distance[shortest_vertex]
           +Graph_Matrix[shortest_vertex][j];
         }       
      }
   }
}
