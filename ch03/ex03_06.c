#include <stdio.h>
#include <stdlib.h>
void PrintPoly(int Poly[],int items)
{  
	int i,MaxExp;
	MaxExp=Poly[0];
	for(i=1;i<=Poly[0]+1;i++)
	{  
		MaxExp--;
		if(Poly[i]!=0)					/*如果该项式为0就跳过*/
		{  
			if((MaxExp+1)!=0)
				printf(" %dX^%d ",Poly[i],MaxExp+1);
			else
				printf(" %d",Poly[i]);
			if(MaxExp>=0)
				printf("%c",'+');      
		}
	}
	printf("\n");
}
void PolyADD(int Poly1[6],int Poly2[6])
{  
	int i;
	int result[6];
	result[0] = Poly1[0];
	for(i=1;i<=Poly1[0]+1;i++)
		result[i]=Poly1[i]+Poly2[i];	/*等幂的系数相加*/
	PrintPoly(result,6);
}
int main()
{  
	int PolyA[6]={4,8,4,0,16,2};		/*声明多项式A*/
	int PolyB[6]={4,5,25,32,0,9};		/*声明多项式B*/
	printf("多项式A= ");
	PrintPoly(PolyA,6);				/*打印出多项式A*/
	printf("------------------------------------------\n");
	printf("多项式B= ");
	PrintPoly(PolyB,6);				/*打印出多项式B*/
	printf("------------------------------------------\n");
	printf("A+B = ");
	PolyADD(PolyA,PolyB);				/*多项式A+多项式B*/
	printf("------------------------------------------\n");
	system("pause");
}
