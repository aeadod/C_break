#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select,student_no=0,num=0;
    float Msum=0,Esum=0;
    
    struct student
    {
        char name[20];
        int Math;
        int Eng;
        char no[10];
        struct student *next;
    };
    typedef struct student s_data;
    s_data *ptr;        /* 存取指针 */
    s_data *head;       /* 链表头指针 */
    s_data *new_data;   /* 新增元素所在位置的指针 */
    
    head = (s_data*) malloc(sizeof(s_data)); /* 建立链表头 */ 
    head->next=NULL;
    ptr = head;  
    do
    {
        printf("(1)新增 (2)离开 =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("姓名 学号 数学成绩 英语成绩:");
            new_data = (s_data*) malloc(sizeof(s_data));    /* 新增下一个元素 */
            scanf("%s %s %d %d",new_data->name,new_data->no,&new_data->Math,&new_data->Eng);
            ptr->next=new_data; /*存取指针设置为新元素所在位置 */
            new_data->next =NULL;   /* 下一个元素的next先设置为null */
            ptr=ptr->next;
            num++;
            
        }
    } while (select != 2);
    ptr = head->next;    /* 设置存取指针从头开始 */
    putchar('\n');
    while (ptr!= NULL)
    {
        printf("姓名：%s\t学号:%s\t数学成绩:%d\t英语成绩:%d\n", 
         ptr->name,ptr->no,ptr->Math,ptr->Eng);
        Msum+=ptr->Math;
        Esum+=ptr->Eng;
        student_no++;
        ptr= ptr ->next;    /* 将ptr移往下一个元素 */
    }
    printf("---------------------------------------------------------\n");
    printf("本链表学生数学平均成绩:%.2f 英语平均成绩:%.2f\n",Msum/student_no,Esum/student_no); 
    system("pause");
    return 0;
}
