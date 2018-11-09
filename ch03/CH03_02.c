#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct student
    {
        char name[20];
        int score;
    };
    
    typedef struct student s_data;	/* 定义类型名称为s_data */
    s_data *new_student;    		/* 声明一个结构指针 */

    new_student = (s_data*) malloc(sizeof(s_data));   /* 给结构变量分配内存空间 */

    
        printf("姓名：");
        scanf("%s", new_student->name);
        printf("成绩：");
        scanf("%d", &new_student->score);


    printf("姓名：%s\t成绩：%d\n", new_student->name, new_student->score);
    
    free(new_student);/* 释放此结构变量的内存 */ 

    system("pause");
    return 0;
}
