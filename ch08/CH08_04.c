#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int fib(int n)
{
    if(n==1 || n==0)
        return n;
    else
        return fib(n-1)+fib(n-2);
}

int fib_search(int data[MAX],int SearchKey)
{
    int index=2; 
    /*쳲��������е���Ѱ*/
    while(fib(index)<=MAX)
        index++;
    index--;
    /* index >=2 */
    /*��ʼ��쳲�������*/
    int RootNode=fib(index);
    /*��һ��쳲�������*/
    int diff1=fib(index-1); 
    /*������쳲���������diff2=fib(index-2)*/
    int diff2=RootNode-diff1;
    RootNode--;/*������ʽ�����������±��Ǵ�0��ʼ��������*/
    while(1)
    {
       if(SearchKey==data[RootNode])
       {
          return RootNode;
       }
       else
       {
           if(index==2) return MAX; /*û���ҵ�*/
           if(SearchKey<data[RootNode])
           {
              RootNode=RootNode-diff2;/*����������쳲������� */
              int temp=diff1;
              diff1=diff2;/*��һ��쳲�������*/
              diff2=temp-diff2;/*������쳲�������*/
              index=index-1;
           }
           else
           {
              if(index==3) return MAX;
              RootNode=RootNode+diff2;/*����������쳲������� */
              diff1=diff1-diff2;/*��һ��쳲�������*/
              diff2=diff2-diff1;/*������쳲�������*/
              index=index-2;
           }         
       }
    }
}

int main(void)
{  
	int data[]={5,7,12,23,25,37,48,54,68,77,
                91,99,102,110,118,120,130,135,136,150};
    int val;
    int i=0;
    int j=0;
	while(1)
	{  
		printf("��������Ҽ�ֵ(1-150)������-1������");
		scanf("%d",&val);/*������ҵ���ֵ*/
		if(val==-1)/*����ֵΪ-1������ѭ��*/
			break;
		int RootNode=fib_search(data,val);/*����쳲��������ҷ���������*/
		if(RootNode==MAX)
			printf("##### û���ҵ�[%3d] #####\n",val);
		else
			printf("�ڵ� %2d��λ���ҵ� [%3d]\n",RootNode+1,data[RootNode]);
	}
	printf("�������ݣ�\n");
	for(i=0;i<2;i++)
	{ 
		for(j=0;j<10;j++)
			printf("%3d-%-3d",i*10+j+1,data[i*10+j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
