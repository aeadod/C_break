#include <iostream>
#include <cstdlib>
using namespace std;
#define length 40

void string_copy(char arr1[],char arr2[]);// 声明拷贝函数原型 

int main()
{
     char Str1[length];  //定义字符数组 Str1[40] 
     char Str2[length];    //定义字符数组 Str2[40] 
     
     cout<<"请输入准备拷贝的字符串:"; 
     cin>>Str1;// 输入字符串
     string_copy(Str1,Str2);//调用函数 
     cout<<"拷贝后的字符串:"<<Str2<<endl;
     
     system("pause");
     return 0;
}

void string_copy(char arr1[],char arr2[])
{
  int i;
  for(i=0;i<length;i++)
  arr2[i]=arr1[i];//逐一拷贝字符  
}
