#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{
	NONE=0,
	ROOM0=1<<0,
	ROOM1=1<<1,
	ROOM2=1<<2,
	ROOM3=1<<3,
}Authorities_t;
Authorities_t common_door =ROOM3|ROOM2|ROOM1|ROOM0;
typedef struct {
	char *name_;
	Authorities_t authority_:4;
	unsigned int id_:24;
}Employee_t;
void init(Employee_t *person,const char *name,Authorities_t auth,unsigned int id)
{
	person->name_=strdup(name);
	person->authority_=auth;
	person->id_=id;
}
int getRoomNum(int n){
	int count =-1;
	while(n){
		n>>=1;
		++count;
	}
	return count;
}
void openCommonDoor(){
};
void openRoom(int roomNum){
};
void readFile(const char *filename){
};
int entry(Employee_t *person,Authorities_t room){
	if(person->authority_&room){
		if(room==common_door){
			printf("Note:%s entries common record office.\n",person->name_);
			openCommonDoor();		
		}else{
			int roomNum=getRoomNum(room);
			printf("Note:%s entries record room %d.\n",person->name_,roomNum);
			openRoom(roomNum);
		}
		return 1;

	}
	else {
		if(room==common_door)
		printf("Alarm:%s try to entry common record office.\n",person->name_);
		else 
			printf("Alarm:%s entry record room%d.\n",person->name_,getRoomNum(room));
	return 0;
	}
}
int main(){
	Employee_t *John=(Employee_t*)malloc(sizeof(Employee_t));
	init(John,"John",ROOM2|ROOM1,9527);
	if(!entry(John,common_door))
	return -1;
	readFile("filename1");
	if(!entry(John,ROOM2))
	return -1;
	if(!entry(John,ROOM1))
	return -1;
	if(!entry(John,ROOM0))
	return -1;
	readFile("filename2");
	return 0;
}
