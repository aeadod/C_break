#include<stdio.h>
int main(void)
{  
  int month;    
  printf("请输入月份: ");    
  scanf("%d",&month);    
  if(2<=month & month<=4) 
    printf("充满生机的春天\n");    

  else if(5<=month & month<=7)         
    printf("热力四射的夏季\n");        
     
  else if(month>=8 & month <=10)
    printf("落叶缤纷的秋季\n");    
    
  else if(month==1 |month>=11 & month <=12 )        
    printf("寒风刺骨的冬季\n");        
      
  else        
    printf("很抱歉没有这个月份!!!");  
  system("pause");          
  return 0; 
}
