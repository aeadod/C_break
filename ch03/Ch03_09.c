#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select,student_no=0;
    float Msum=0,Esum=0;
    
    struct student
    {
        char name[20];
        char no[10];
        struct student *next;
    };
    typedef struct student s_data;
    s_data *ptr;        /* 存取指针 */
    s_data *head;       /* 链表头指针*/
    s_data *new_data;   /* 新增元素所在位置的指针 */

    head = (s_data*) malloc(sizeof(s_data));   /* 新增链表头元素 */
    ptr = head;    /* 设置存取指针位置 */
    ptr->next = NULL;    /* 当前无下一个元素 */
    do
    {
        printf("(1)新增 (2)离开 =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("姓名 学号 :");
            scanf("%s %s",ptr->name,ptr->no);
            new_data = (s_data*) malloc(sizeof(s_data));    /* 新增下一个元素 */
            ptr->next = new_data;    /* 连接下一个元素 */
            new_data->next = NULL;   /* 下一个元素的next先设置为null */
            ptr = new_data;    /* 存取指针设置为新元素所在位置 */
        }
    } while (select != 2);
    
    ptr->next = head;    /* 设置存取指针从头开始 */

    putchar('\n');
    ptr=head;
    do
    {
        printf("姓名：%s\t学号:%s\n", 
        ptr->name,ptr->no);
        ptr = ptr ->next;    /* 将head移往下一个元素 */
    } while(ptr->next!= head);
    printf("---------------------------------------------------------\n");
    
    system("pause");
    return 0;
}
