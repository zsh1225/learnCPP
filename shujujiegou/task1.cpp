#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

typedef struct HNode
{
    char roomN[7];      // 客房名称
    float Price;        // 标准价格
    float PriceL;       // 入住价格(默认值=标准价格*80%)
    int Beds;           // 床位数Beds
    char State[7];      // 入住状态(值域："空闲"、"入住"、"预订"，默认值为"空闲")
    struct HNode *next; // 指针域
} Hotel;

// 初始化函数
Hotel *init_hotel_list()
{
    Hotel *head = (Hotel *)malloc(sizeof(Hotel));
    head->next = NULL;
    Hotel *pRear = NULL;
    Hotel *new_node = NULL;
    FILE *fp;
    if ((fp = fopen("studentInit.dat", "r")) == NULL)
    {
        printf("文件打开失败！\n");
        return NULL;
    }
    while (1)
    {
        if (feof(fp))
            break;
        Hotel *new_node = malloc(sizeof(Hotel));
        fscanf(fp, "%s %f,%d", new_node->roomN, &new_node->Price, &new_node->Beds);
        // fscanf(fp, "%s%s%s%d%d%d%d", &newstu->num, &newstu->name, &newstu->major, &newstu->classNo, &newstu->score[0], &newstu->score[1], &newstu->score[2]);
        new_node->PriceL = new_node->Price * 0.8;
        strcpy(new_node->State, "free");
        if (feof(fp))
            break;
        newstu->next = NULL;
        pRear->next = newstu;
        pRear = newstu;
        stu_count++;
    }
    fclose(fp);
    printf("成功从studentInit.dat文件中读取 %d 条记录！\n", stu_count);
    return header;
}
