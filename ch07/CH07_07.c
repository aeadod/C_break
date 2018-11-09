/* 基数排序法 从小到大排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void radix (int *,int);/* 基数排序法子程序 */
void showdata (int *,int);
void inputarr (int *,int);
int main(void)
{ 
	int size,data[100]={0};
	printf("请输入数组大小(100以下)：");
	scanf("%d",&size);
	printf("您输入的原始数据是：\n");
	inputarr (data,size);
	showdata (data,size);
	radix (data,size);
	system("pause");
	return 0;
}
void inputarr(int data[],int size)
{
	int i;
	srand((unsigned)time(NULL));
	for (i=0;i<size;i++)
		data[i]=(rand()%999)+1;/*设置data值最大为3位数*/
}
void showdata(int data[],int size)
{  
	int i;
	for (i=0;i<size;i++)
		printf("%5d",data[i]);
	printf("\n");
}
void radix(int data[],int size)
{  
	int i,j,k,n,m;
	for (n=1;n<=100;n=n*10)/*n为基数，从个位数开始排序 */
	{  
		int tmp[10][100]={0};/* 设置暂存数组，[0~9位数][数据个数]，所有内容均为0 */
		for (i=0;i<size;i++)/* 对比所有数据 */
		{  
			m=(data[i]/n)%10;/* m为n位数的值，如 36取十位数 (36/10)%10=3 */
			tmp[m][i]=data[i];/* 把data[i]的值暂存于tmp 里 */
		}
		k=0;
		for (i=0;i<10;i++)
		{  
			for(j=0;j<size;j++)
			{  
				if(tmp[i][j] != 0)	/* 因一开始设置 tmp ={0}，故不为0者即为 */
				{  
					data[k]=tmp[i][j];/* data暂存在 tmp 里的值，把tmp 里的值放 */
					k++;		      /* 回data[ ]里 */
				}
			}
		}
		printf("经过%3d位数排序后：",n);
		showdata(data,size);
	}
}
