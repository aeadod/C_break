#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct student
    {
        char name[20];
        int score;
        struct student *next;
    }; /* 定义 student 节点 */ 
    struct student s[3]; /* 声明结构数组 */ 
    int i;
    struct student *ptr;    /* 设置读取指针 */

    /* 设置结构成员与链表的下一个地址 */
    for(i = 0; i < 3; i++)
    {
        printf("姓名：");
        scanf("%s", s[i].name); /* 输入学生姓名 */ 
        printf("成绩：");
        scanf("%d", &s[i].score);/* 输入学生成绩 */ 
        if (i != 2)
            s[i].next = &s[i+1];/* 指向下一个节点 */ 
        else
            s[i].next = NULL;/* 最后一个节点指向 NULL */ 
    }
    ptr = &s[0];/* ptr 指向链表的第一个节点 */ 
    printf("---------------------------------\n");
    while(ptr != NULL)
    {
        printf("姓名：%s\t成绩：%d\n", ptr->name, ptr->score);
        ptr = ptr->next;/* 遍历下一个节点 */ 
    }/* 遍历链表并显示内容 */
    system("pause");
    return 0;
}
