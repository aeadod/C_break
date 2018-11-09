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
    /*斐波拉契数列的搜寻*/
    while(fib(index)<=MAX)
        index++;
    index--;
    /* index >=2 */
    /*起始的斐波拉契数*/
    int RootNode=fib(index);
    /*上一个斐波拉契数*/
    int diff1=fib(index-1); 
    /*上两个斐波拉契数即diff2=fib(index-2)*/
    int diff2=RootNode-diff1;
    RootNode--;/*这个表达式是配合数组的下标是从0开始储存数据*/
    while(1)
    {
       if(SearchKey==data[RootNode])
       {
          return RootNode;
       }
       else
       {
           if(index==2) return MAX; /*没有找到*/
           if(SearchKey<data[RootNode])
           {
              RootNode=RootNode-diff2;/*左子树的新斐波拉契数 */
              int temp=diff1;
              diff1=diff2;/*上一个斐波拉契数*/
              diff2=temp-diff2;/*上两个斐波拉契数*/
              index=index-1;
           }
           else
           {
              if(index==3) return MAX;
              RootNode=RootNode+diff2;/*右子树的新斐波拉契数 */
              diff1=diff1-diff2;/*上一个斐波拉契数*/
              diff2=diff2-diff1;/*上两个斐波拉契数*/
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
		printf("请输入查找键值(1-150)，输入-1结束：");
		scanf("%d",&val);/*输入查找的数值*/
		if(val==-1)/*输入值为-1就跳离循环*/
			break;
		int RootNode=fib_search(data,val);/*利用斐波拉契查找法查找数据*/
		if(RootNode==MAX)
			printf("##### 没有找到[%3d] #####\n",val);
		else
			printf("在第 %2d个位置找到 [%3d]\n",RootNode+1,data[RootNode]);
	}
	printf("数据内容：\n");
	for(i=0;i<2;i++)
	{ 
		for(j=0;j<10;j++)
			printf("%3d-%-3d",i*10+j+1,data[i*10+j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
