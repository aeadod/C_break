#include <stdio.h>
#include <stdlib.h>

void merge(FILE *fp, FILE *fp1, FILE *fp2)
{  
	int n1,n2;/*��������n1��n2�ݴ������ļ�data1��data2�ڵ�Ԫ��ֵ*/
	n1=getc(fp1);/*��fp1��ȡһ��Ԫ�ؽ���������n1*/
	n2=getc(fp2);
	while(feof(fp1)==0 && feof(fp2)==0)/*�ж��Ƿ��ѵ��ļ�β*/
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
		putc(n2,fp);/*����һ�������ļ��ڵ�����ȫ���ŵ�fp��*/
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
	FILE *fp=fopen("data.txt","w+");/*�������򿪽������ļ���ָ�� fp*/
	FILE *fp1=fopen("data1.txt","r");/*���������ļ�1ָ�� fp1*/
	FILE *fp2=fopen("data2.txt","r");/*���������ļ�2ָ�� fp2*/
	FILE *f,*f1,*f2;
	if(fp==NULL)
		printf("�����ļ�ʧ��\n");
	else if(fp1==NULL)
		printf("�������ļ� 1 ʧ��\n");/*���ļ��ɹ�ʱ��ָ��᷵��FILE�ļ�*/
	else if(fp2==NULL)/*ָ�룬��ʧ���򷵻�NULLֵ*/
		printf("�������ļ� 2 ʧ��\n");
	else
	{  
		printf("����������......\n");
        merge(fp,fp1,fp2);
		printf("���ݴ������!!\n");
	}
	fclose(fp);	/*�ر��ļ�*/
	fclose(fp1);
	fclose(fp2);

	printf("data1.txt��������Ϊ��\n");
	f1=fopen("data1.txt","r");
	while(1)
	{  
		n=getc(f1);
		if(feof(f1)) break;
			printf("[%c] ",n);
	}
	printf("\n");
	printf("data2.txt��������Ϊ��\n");
	f2=fopen("data2.txt","r");
	while(1)
	{  
		n=getc(f2);
		if(feof(f2)) break;
			printf("[%c] ",n);
	}
	printf("\n");
	printf("�����data.txt��������Ϊ��\n");
	f=fopen("data.txt","r");
	while(1)
	{  
		n=getc(f);
		if(feof(f)) break;
		printf("[%c] ",n);
	}
	printf("\n");
	printf("\n");
	fclose(f);	/*�ر��ļ�*/
	fclose(f1);
	fclose(f2);
	system("pause");
	return 0;
}
