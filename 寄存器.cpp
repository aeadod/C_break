#include<stdio.h>
typedef unsigned char uchar;
typedef struct{
	uchar bit0:1;
	uchar bit1:1;
	uchar bit2:1;
	uchar bit3:1;
	uchar bit4:1;
	uchar bit5:1;
	uchar bit6:1;
	uchar bit7:1;
}bits;
typedef union{
	uchar data_value;
	bits data_bits;
}utype; 
int main(){
	uchar ch='a';
	uchar *addr=&ch;
	utype value;
	value.data_bits.bit1=1;
	value.data_bits.bit2=0;
	*addr=value.data_value;
	
	
	
//	uchar value=*addr;
//	printf("%d\n",(value&1)!=0);
//	printf("%d\n",(value&2)!=0);
//	printf("%d\n",(value&4)!=0);
//	value=value|2;
//	return 0;
}
