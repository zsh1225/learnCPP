#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using  namespace std;
typedef struct HNode
{
    char roomN[7];      // 客房名称
    float Price;        // 标准价格
    float PriceL;       // 入住价格(默认值=标准价格*80%)
    int Beds;           // 床位数Beds
    char State[7];      // 入住状态(值域："空闲"、"入住"、"预订"，默认值为"空闲")
    struct HNode *next; // 指针域
} Hotel,*HLink;

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
        Hotel *new_node =(Hotel *) malloc(sizeof(Hotel));
        fscanf(fp, "%s %f,%d", new_node->roomN, &new_node->Price, &new_node->Beds);
        // fscanf(fp, "%s%s%s%d%d%d%d", &newstu->num, &newstu->name, &newstu->major, &newstu->classNo, &newstu->score[0], &newstu->score[1], &newstu->score[2]);
        new_node->PriceL = new_node->Price * 0.8;
        strcpy(new_node->State, "free");
        if (feof(fp))
            break;
        new_node->next = NULL;
        pRear->next = new_node;
        pRear = new_node;

    }
    fclose(fp);
    // printf("成功从studentInit.dat文件中读取 %d 条记录！\n", stu_count);
    return head;
}

//实现输出客房信息函数void Exp(HLink H)，输出所有客房的客房名称、标准价格、入住价格、床位数、入住状态
void Exp(HLink H){
    while (H != NULL){
        // printf("客房名称：%s\n", H->roomN);
        // printf("标准价格：%.2f\n", H->Price);
        // printf("入住价格：%.2f\n", H->PriceL);
        // printf("床位数：%d\n", H->Beds);
        // printf("入住状态：%s\n", H->State);
        printf("%s%8.1f%8.1f%6d%8s\n",H->roomN,H->Price,H->PriceL,H->Beds,H->State);
        H = H->next;
    }
}

// 释放链表内存函数
void free_hotel_list(Hotel *head)
{
    Hotel *pRear = NULL;
    while (head != NULL)
    {
        pRear = head;
        head = head->next;
        free(pRear);
    }
}


int main(){
    cout << "Hello, World!" << endl;
}
