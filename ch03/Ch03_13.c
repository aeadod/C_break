#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select;
    
    struct student
    {
        char name[20];
        int Math;
        int Eng;
        char no[10];
        struct student *rlink;
        struct student *llink;
    };
    typedef struct student s_data;
    s_data *ptr;        /* 存取指针 */
    s_data *head;       /* 链表头指针 */
    s_data *new_data;   /* 新增元素所在位置的指针 */

    head = (s_data*) malloc(sizeof(s_data)); 
    head->llink=NULL;
    head->rlink=NULL;
    ptr = head;   /* 设置存取指针开始的位置  */
    do
    {
        printf("(1)新增 (2)离开 =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("姓名 学号 数学成绩 英语成绩:");
            new_data = (s_data*) malloc(sizeof(s_data));    /* 新增下一个元素 */
            scanf("%s %s %d %d",new_data->name,new_data->no,&new_data->Math,&new_data->Eng); 
            /*输入节点结构中的数据 */
            ptr->rlink=new_data;
            new_data->rlink = NULL;   /* 下一个元素的next先设置为null */
            new_data->llink=ptr;   /* 存取指针设置为新元素所在的位置 */
            ptr=new_data;
        }
    } while (select != 2);

    ptr = head->rlink;    /* 设置存取指针从链表头的右指针所指节点开始 */
    putchar('\n');
    
    while (ptr!= NULL)
    {
     printf("姓名：%s\t学号:%s\t数学成绩:%d\t英语成绩:%d\n", ptr->name,ptr->no,ptr->Math,ptr->Eng);    
     ptr = ptr ->rlink;    /* 将ptr移往右边下一个元素 */   
     }
        
    system("pause");
    return 0;
}
