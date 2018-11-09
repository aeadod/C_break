#include <stdio.h>
#include <stdlib.h>
void PrintPoly(int Poly[],int items)
{  
	int i,MaxExp;
	MaxExp=Poly[0];
	for(i=1;i<=Poly[0]+1;i++)
	{  
		MaxExp--;
		if(Poly[i]!=0)					/*�������ʽΪ0������*/
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
		result[i]=Poly1[i]+Poly2[i];	/*���ݵ�ϵ�����*/
	PrintPoly(result,6);
}
int main()
{  
	int PolyA[6]={4,8,4,0,16,2};		/*��������ʽA*/
	int PolyB[6]={4,5,25,32,0,9};		/*��������ʽB*/
	printf("����ʽA= ");
	PrintPoly(PolyA,6);				/*��ӡ������ʽA*/
	printf("------------------------------------------\n");
	printf("����ʽB= ");
	PrintPoly(PolyB,6);				/*��ӡ������ʽB*/
	printf("------------------------------------------\n");
	printf("A+B = ");
	PolyADD(PolyA,PolyB);				/*����ʽA+����ʽB*/
	printf("------------------------------------------\n");
	system("pause");
}
