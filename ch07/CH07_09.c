#include <stdio.h>
#include <stdlib.h>

void merge (FILE *,FILE *,FILE *);/*�����ϲ������ӳ���*/
void me (FILE *,FILE *,FILE *,FILE *);/*�����ָ��ļ��ӳ���*/
void bubble(FILE *,int);/*�ѷָ��ļ��У���ð�����򷨽����ڲ�����*/
void showdata(FILE *); /*����ļ�����*/
int main(void)
{  
	char n;
	FILE *fp=fopen("datafile.txt","r");/*�����ļ�ָ��*/
	FILE *fp1=fopen("sortdata.txt","w+");
	FILE *ff1=fopen("sort1.txt","w+");
	FILE *ff2=fopen("sort2.txt","w+");

	if(fp==NULL)/*�ļ��Ƿ�򿪳ɹ�*/
		printf("��ԭ�����ļ�ʧ��\n");
	else if(fp1==NULL)
       	printf("�򿪺ϲ����ļ�ʧ��\n");
	else if(ff1==NULL)
        printf("�򿪷ָ��ļ� 1 ʧ��\n");
	else if(ff2==NULL)
        printf("�򿪷ָ��ļ� 2 ʧ��\n");
	else
	{  
		printf("�ļ��ָ���......\n");
        me(fp,fp1,ff1,ff2);
		printf("�ļ�������......\n");
		printf("���ݴ������!!\n");
	}

	rewind(fp); /*��������ļ�ָ��*/
	rewind(fp1);
	rewind(ff1);
	rewind(ff2);
    /*��ӡ�ļ�����*/
	printf("ԭʼ�ļ�datafile.txt��������Ϊ��\n");
	showdata(fp);
	printf("\n�ָ��ļ�sort1.txt��������Ϊ��\n");
	showdata(ff1);
	printf("\n�ָ��ļ�sort2.txt��������Ϊ��\n");
	showdata(ff2);
	printf("\n�����sortdata.txt��������Ϊ��\n");

	showdata(fp1);

	fclose(fp);/*�ر��ļ�*/
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
		n1++;/*������n1Ϊdatafile��������*/
	}

	rewind(fp);
	for(n2=0;n2<(n1/2);n2++)
	{  
		da2=getc(fp);/*��һ����ļ�*/
	    putc(da2,ff1);/*�ָff1ȥ*/
	}
	rewind(ff1);
    bubble(ff1,n2);/*�ָ�������bubble�ӳ����������*/

	while(1)
	{  
		da2=getc(fp);/*��������datafile�ļ�*/
	    if(feof(fp)) break;
			putc(da2,ff2);/*���ݷָff2ȥ*/
	}
	rewind(ff2);
	bubble(ff2,(n1/2));/*�ָ�������bubble�ӳ����������*/

	rewind(ff1);
	rewind(ff2);
	merge(fp1,ff1,ff2);/*���úϲ������ӳ���*/
}
void merge(FILE *fp, FILE *fp1, FILE *fp2)
{  
	char n1,n2;	/*��������n1��n2�ݴ������ļ�data1��data2�ڵ�Ԫ��ֵ*/
	n1=getc(fp1);/*��fp1��ȡһ��Ԫ�ؽ���������n1*/
	n2=getc(fp2);
	while(feof(fp1)==0 && feof(fp2)==0)	/*�ж��Ƿ��ѵ��ļ�β*/
	{  
		if (n1 <= n2)
		{  
			putc(n1,fp);/*���n1�Ƚ�С�����n1�浽fp��*/
			n1=getc(fp1);/*���Ŷ���һ�� n1 ������*/
		}
		else
		{  
			putc(n2,fp);/*���n2�Ƚ�С�����n2�浽fp��*/
			n2=getc(fp2);/*���Ŷ���һ�� n2������*/
		}
	}
	if(feof(fp1))/*�������һ�������ļ��Ѷ�ȡ��ϣ����жϺ�*/
	{ 
		putc(n2,fp);/*����һ�������ļ��ڵ�����ȫ���ŵ� fp ��*/
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
		flag=0;/*flag�����ж��Ƿ���ִ�н����Ĳ���*/
		for (j=0;j<i;j++)
		{  
			if(data[j+1]<data[j])
			{  
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;
			}/*���ִ�й���������flag��Ϊ0*/
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
