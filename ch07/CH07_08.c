#include <stdio.h>
#include <stdlib.h>

void merge(FILE *fp, FILE *fp1, FILE *fp2)
{  
	int n1,n2;/*声明变量n1，n2暂存数据文件data1和data2内的元素值*/
	n1=getc(fp1);/*从fp1中取一个元素进来，存在n1*/
	n2=getc(fp2);
	while(feof(fp1)==0 && feof(fp2)==0)/*判断是否已到文件尾*/
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
		putc(n2,fp);/*把另一个数据文件内的数据全部放到fp里*/
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
		while(feof(fp1))
		{  
			n1=getc(fp1);
			putc(n1,fp);
		}
	}	 
}

int main(void)
{  
	char n;
	FILE *fp=fopen("data.txt","w+");/*声明并打开建立新文件主指针 fp*/
	FILE *fp1=fopen("data1.txt","r");/*声明数据文件1指针 fp1*/
	FILE *fp2=fopen("data2.txt","r");/*声明数据文件2指针 fp2*/
	FILE *f,*f1,*f2;
	if(fp==NULL)
		printf("打开主文件失败\n");
	else if(fp1==NULL)
		printf("打开数据文件 1 失败\n");/*打开文件成功时，指针会返回FILE文件*/
	else if(fp2==NULL)/*指针，打开失败则返回NULL值*/
		printf("打开数据文件 2 失败\n");
	else
	{  
		printf("数据排序中......\n");
        merge(fp,fp1,fp2);
		printf("数据处理完成!!\n");
	}
	fclose(fp);	/*关闭文件*/
	fclose(fp1);
	fclose(fp2);

	printf("data1.txt数据内容为：\n");
	f1=fopen("data1.txt","r");
	while(1)
	{  
		n=getc(f1);
		if(feof(f1)) break;
			printf("[%c] ",n);
	}
	printf("\n");
	printf("data2.txt数据内容为：\n");
	f2=fopen("data2.txt","r");
	while(1)
	{  
		n=getc(f2);
		if(feof(f2)) break;
			printf("[%c] ",n);
	}
	printf("\n");
	printf("排序后data.txt数据内容为：\n");
	f=fopen("data.txt","r");
	while(1)
	{  
		n=getc(f);
		if(feof(f)) break;
		printf("[%c] ",n);
	}
	printf("\n");
	printf("\n");
	fclose(f);	/*关闭文件*/
	fclose(f1);
	fclose(f2);
	system("pause");
	return 0;
}
