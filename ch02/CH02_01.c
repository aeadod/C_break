#include <stdio.h>
#include <stdlib.h>

int main()
{
     int Score[5]={ 87,66,90,65,70 };    
      /* ������������Score[5], ������5��ɼ� */
     int count, Total_Score=0;
     for (count=0; count < 5; count++)   /* ִ�� for ѭ����ȡѧ���ĳɼ� */
     {
       printf("�� %d λѧ���ķ���:%d\n", count+1,Score[count]);  
       Total_Score+=Score[count];  /* �������ж�ȡ���������ܺ� */
      }
      printf("-------------------------\n");
      printf("5λѧ�����ܷ�:%d\n", Total_Score);  
     /* ����ɼ��ܷ� */
     
     system("pause");
     return 0;
}
