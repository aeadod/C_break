#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	int A[3][3] = {{1,3,5},{7,9,11},{13,15,17}};/* ��ά��������� */ 
	int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};/* ��ά��������� */
	int C[3][3] = {0};
	
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	    C[i][j]=A[i][j]+B[i][j];/* ����C=����A+����B */
	
	printf("[����A�;���B��ӵĽ��]\n");	/*���A+B������*/
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",C[i][j]);
		printf("\n");
	}
	
	system("pause");
	return 0;
}
