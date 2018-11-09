#include <stdio.h>
#include <stdlib.h>

void merge (FILE *,FILE *,FILE *);/*声明合并排序子程序*/
void me (FILE *,FILE *,FILE *,FILE *);/*声明分割文件子程序*/
void bubble(FILE *,int);/*已分割文件中，以冒泡排序法进行内部排序*/
void showdata(FILE *); /*输出文件内容*/
int main(void)
{  
	char n;
	FILE *fp=fopen("datafile.txt","r");/*声明文件指针*/
	FILE *fp1=fopen("sortdata.txt","w+");
	FILE *ff1=fopen("sort1.txt","w+");
	FILE *ff2=fopen("sort2.txt","w+");

	if(fp==NULL)/*文件是否打开成功*/
		printf("打开原数据文件失败\n");
	else if(fp1==NULL)
       	printf("打开合并后文件失败\n");
	else if(ff1==NULL)
        printf("打开分割文件 1 失败\n");
	else if(ff2==NULL)
        printf("打开分割文件 2 失败\n");
	else
	{  
		printf("文件分割中......\n");
        me(fp,fp1,ff1,ff2);
		printf("文件排序中......\n");
		printf("数据处理完成!!\n");
	}

	rewind(fp); /*重设各个文件指针*/
	rewind(fp1);
	rewind(ff1);
	rewind(ff2);
    /*打印文件内容*/
	printf("原始文件datafile.txt数据内容为：\n");
	showdata(fp);
	printf("\n分割文件sort1.txt数据内容为：\n");
	showdata(ff1);
	printf("\n分割文件sort2.txt数据内容为：\n");
	showdata(ff2);
	printf("\n排序后sortdata.txt数据内容为：\n");

	showdata(fp1);

	fclose(fp);/*关闭文件*/
	fclose(fp1);
	fclose(ff1);
	fclose(ff2);
	system("pause");
	return 0;
}
void me(FILE *fp,FILE *fp1,FILE *ff1,FILE *ff2)
{  
	int n1=0,n2=0;
	char da1,da2;
	while(1)
	{                          
		da1=getc(fp);
		if(feof(fp)) break;
		n1++;/*计数，n1为datafile的总项数*/
	}

	rewind(fp);
	for(n2=0;n2<(n1/2);n2++)
	{  
		da2=getc(fp);/*把一半的文件*/
	    putc(da2,ff1);/*分割到ff1去*/
	}
	rewind(ff1);
    bubble(ff1,n2);/*分割完后调用bubble子程序进行排序*/

	while(1)
	{  
		da2=getc(fp);/*把其他的datafile文件*/
	    if(feof(fp)) break;
			putc(da2,ff2);/*内容分割到ff2去*/
	}
	rewind(ff2);
	bubble(ff2,(n1/2));/*分割完后调用bubble子程序进行排序*/

	rewind(ff1);
	rewind(ff2);
	merge(fp1,ff1,ff2);/*调用合并排序子程序*/
}
void merge(FILE *fp, FILE *fp1, FILE *fp2)
{  
	char n1,n2;	/*声明变量n1，n2暂存数据文件data1和data2内的元素值*/
	n1=getc(fp1);/*从fp1中取一个元素进来，存在n1*/
	n2=getc(fp2);
	while(feof(fp1)==0 && feof(fp2)==0)	/*判断是否已到文件尾*/
	{  
		if (n1 <= n2)
		{  
			putc(n1,fp);/*如果n1比较小，则把n1存到fp里*/
			n1=getc(fp1);/*接着读下一项 n1 的数据*/
		}
		else
		{  
			putc(n2,fp);/*如果n2比较小，则把n2存到fp里*/
			n2=getc(fp2);/*接着读下一项 n2的数据*/
		}
	}
	if(feof(fp1))/*如果其中一个数据文件已读取完毕，经判断后*/
	{ 
		putc(n2,fp);/*把另一个数据文件内的数据全部放到 fp 里*/
		while (1)
		{  
			n2=getc(fp2);
			if(feof(fp2)) break;
			putc(n2,fp);
		}
	}
	else if (feof(fp2))
	{ 
		putc(n1,fp);
		while (feof(fp1))
		{  
			n1=getc(fp1);
			putc(n1,fp);
		}
	}	 
}
void bubble (FILE *ff,int size)
{
	int ii=0,j,i,tmp,flag;
	char n;
	char data[100]={0};
	for(i=0;i<size;i++)
	{  
		n=getc(ff);
		if(feof(ff)) break;
		data[i]=n;
		ii++;
	}
	for(i=size;i>0;i--)
	{  
		flag=0;/*flag用来判断是否有执行交换的操作*/
		for (j=0;j<i;j++)
		{  
			if(data[j+1]<data[j])
			{  
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;
			}/*如果执行过交换，则flag不为0*/
		}
		if(flag==0)break;
	}
	rewind(ff);
	for(i=1;i<=size;i++)
		putc(data[i],ff);
}
void showdata (FILE *ff)
{   
	char n;
	while(1)
	{  
		n=getc(ff);
		if(feof(ff)) break;
			printf("[%c]",n);
	}
	printf("\n");
}
