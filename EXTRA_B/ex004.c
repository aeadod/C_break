#include<stdio.h>
int main(void)
{  
  int month;    
  printf("�������·�: ");    
  scanf("%d",&month);    
  if(2<=month & month<=4) 
    printf("���������Ĵ���\n");    

  else if(5<=month & month<=7)         
    printf("����������ļ�\n");        
     
  else if(month>=8 & month <=10)
    printf("��Ҷ�ͷ׵��＾\n");    
    
  else if(month==1 |month>=11 & month <=12 )        
    printf("����̹ǵĶ���\n");        
      
  else        
    printf("�ܱ�Ǹû������·�!!!");  
  system("pause");          
  return 0; 
}
