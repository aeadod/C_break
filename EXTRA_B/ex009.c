#include<stdio.h>
#include<string.h>
int main(void)
{
	int i;
	char choice;
	/*�����ַ������鲢��ʼ��*/
 	char newspaper[5][20]={{"1.ˮ���ձ�"},
 							{"2.�����ձ�"},
        					{"3.���ɱ�"},
             				{"4.�й��ձ�"},
                 			{"5.����Ҫ"}};
	/*�ַ�����������*/
	for(i=0; i<5; i++)
	{
		printf("%s  ",newspaper[i]);
	}
 	printf("������ѡ��:");
 	choice=getche();
 	printf("\n");
 	choice=choice-'0';
 	/*������ж�*/
 	if(choice>=0 && choice<4)
 	{
  		printf("%s",newspaper[choice-1]);
    	printf("\nлл���Ķ���!!!\n");
    }	
    else if(choice==5)
  		printf("\n��л���Ĳο�!!!\n");
  	else
  		printf("�������\n");
	system("pause");
	return 0;
}
