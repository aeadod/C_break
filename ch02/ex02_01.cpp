#include <iostream>
#include <cstdlib>
using namespace std;
#define length 40

void string_copy(char arr1[],char arr2[]);// ������������ԭ�� 

int main()
{
     char Str1[length];  //�����ַ����� Str1[40] 
     char Str2[length];    //�����ַ����� Str2[40] 
     
     cout<<"������׼���������ַ���:"; 
     cin>>Str1;// �����ַ���
     string_copy(Str1,Str2);//���ú��� 
     cout<<"��������ַ���:"<<Str2<<endl;
     
     system("pause");
     return 0;
}

void string_copy(char arr1[],char arr2[])
{
  int i;
  for(i=0;i<length;i++)
  arr2[i]=arr1[i];//��һ�����ַ�  
}
