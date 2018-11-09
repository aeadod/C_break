#include <stdio.h>
#include <stdlib.h>
#include <string.h>/* 包含字串處理函數 */ 

int push(char*, int);    /* 置入堆疊資料 */
int pop();           /* 取出堆疊資料 */
int show();          /* 顯示堆疊資料 */

struct student
{
    char name[20];
    int score;
    struct student *next;
};
typedef struct student s_data;
s_data *top = NULL;

int main()
{
    int select, score;
    char name[20];

    do
    {
        printf("(1)存入 (2)取出 (3)走訪 (4)離開 => ");
        scanf("%d", &select);
        switch (select)
        {
            case 1:
                printf("姓名 成績：");
                scanf("%s %d", name, &score);
                push(name, score);
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
        }
    } while (select != 4);
    
    system("pause");
    return 0;
}

int push(char* name, int score)/* 存入新元素 */
{
    s_data *new_data;

    new_data = (s_data*) malloc(sizeof(s_data));    /* 配置空間給新元素 */
    strcpy(new_data->name, name);    /* 設定新元素的資料內容 */
    new_data->score = score;
    new_data->next = top;    /* 將新元素的next指向原堆疊頂端 */
    top = new_data;    /* 設定新元素為堆疊頂端 */
}

int pop() /* 取出新元素 */
{
    s_data *freeme;

    if(top != NULL)   /* 如果堆疊不為空 */
    {
        printf("姓名：%s\t成績：%d......取出\n", top->name, top->score);
        freeme = top;   /* 設定freeme指標，待會要釋放它所指向的位置 */
        top = top->next;    /* 設定新堆疊頂端 */
        free(freeme);    /* 釋放freeme指向的記憶體空間 */
    }
    else
        printf("堆疊已空！\n");
}

int show()/* 走訪堆疊陣列 */
{
    s_data *ptr;
    ptr = top;
    if (ptr == NULL)    /* 如果指向空位址，表示堆疊為空 */
        printf("堆疊已空\n");
    else
    {
        while (ptr != NULL)    /* 由上往下走訪堆疊 */
        {
            printf("姓名：%s\t成績：%d\n", ptr->name, ptr->score);
            ptr = ptr->next;
        }
    }
}
