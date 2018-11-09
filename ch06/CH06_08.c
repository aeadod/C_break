#include <stdio.h>
#include <stdlib.h>
#define SIZE   7  
#define INFINITE  99999 
#define NUMBER 6

int Graph_Matrix[SIZE][SIZE];/* ͼ������ */
int distance[SIZE][SIZE];/* ·���������� */

/* ����ͼ */
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;/* �ߵ���� */
   int End_Point; /* �ߵ��յ� */
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if (i==j)
            Graph_Matrix[i][j] = 0; /* �Խ�����Ϊ0 */
         else
            Graph_Matrix[i][j] = INFINITE;  
   /* ����ͼ�ı� */  
   i=0;
   while(i<SIZE)
   {
      Start_Point = Path_Cost[i*3]; 
      End_Point = Path_Cost[i*3+1]; 
      Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
      i++;
   }
}
/* ���ͼ�� */
 
void shortestPath(int vertex_total)
{       
   int i,j,k;
   /* ͼ�ĳ��������ʼ��  */
   for (i=1;i<=vertex_total;i++ )
      for (j=i;j<=vertex_total;j++ )
         {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
         }
     /* ����Floyd�㷨�ҳ����ж�������֮�����̾��� */       
   for (k=1;k<=vertex_total;k++ ) 
      for (i=1;i<=vertex_total;i++ )
         for (j=1;j<=vertex_total;j++ )
            if (distance[i][k]+distance[k][j]<distance[i][j])
                distance[i][j] = distance[i][k] + distance[k][j];   
}
/* ������ */
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
   printf("      ���ж�������֮�����̾���: \n");
   printf("===========================================\n");
   shortestPath(NUMBER); /* �������ж��������·�� */
   /*����������������·����������󣬽������*/
   printf("       ����1 ����2 ����3 ����4 ����5 ����6\n");
      for ( i = 1; i <= NUMBER; i++ )
      {
         printf("����%d",i);
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

