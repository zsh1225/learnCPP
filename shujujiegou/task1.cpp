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
    if ((fp = fopen("HotelInit.txt", "r")) == NULL)
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
//实现创建客房信息链表函数void Build(HLink &H)，输入（客房名称、标准价格、床位数），同时修改入住价格、入住状态为默认值，即入住价格=标准价格*80%，入住状态为”空闲”（提示：用strcpy()字符串拷贝函数）。为了提高程序调试效率，要求：用文件操作来输入客房信息（客房名称、标准价格、床位数）；
void Build(HLink &H){
    H = init_hotel_list();
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

//函数int Find(HLink &H, char *roomN)，查找房间名称为roomN的客房。
//如果找到，则返回该客房在链表中的位置序号（>=1），否则返回0。提示：用strcmp()字符串比较函数；
int Find(HLink &H, char *roomN){
    HLink p = H;
    int i = 1;
    while (p != NULL && strcmp(p->roomN, roomN)){
        p = p->next;
        i++;
    }
    return p != NULL ? i : 0;
}

//实现函数void updateH(HLink &H, int beds, char *state)，将床位数为beds的客房入住状态改为state。提示：用strcpy()字符串拷贝函数；
void updateH(HLink &H, int beds, char *state){
    while (H != NULL && strcmp(H->roomN, state)){
        H = H->next;
    }
    if (H != NULL){
        H->Beds = beds;
        strcpy(H->State, state);
    }
}

//函数void Add(HLink &H)，将该链表中未入住的客房入住价格均加价20%；
void Add(HLink &H){
    HLink p = H;
    while (p != NULL && strcmp(p->State, "free")){
        p = p->next;
    }
    if (p != NULL){
        p->PriceL *= 1.2;
    }
}

//求出入住价格最高的客房函数HLink FirstH(HLink &H)，该函数内return语句返回入住价格最高的客房结点指针，返回前将该结点在链表中删除；
HLink FirstH(HLink &H){
    HLink p = H;
    while (p->next != NULL && p->next->Price > p->Price){
        p = p->next;
    }
    if (p->next != NULL){
        HLink temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
    return p;
}

//函数void MoveK1(HLink &H, int k)，将单链表中倒数第k个结点之后的所有结点移到头结点后面，注意：严禁采用先计算链表长度n再减k（即n-k）的方法；
void MoveK1(HLink &H, int k){
    HLink p = H;
    while (p->next != NULL && k-- > 0){
        p = p->next;
    }
    if (p->next != NULL){
        HLink q = p->next;
        p->next = q->next;
        q->next = H->next;
        H->next = q;
    }
}

//函数void ReverseN2(HLink &H)，将单链表的正中间位置结点之后的全部结点倒置的功能，注意：严禁采用先计算链表长度n再除以2（即n/2）的方法；
void ReverseN2(HLink &H){
    HLink p = H;
    HLink pre = NULL;
    int count = 0;
    while (p != NULL && count < (p->next - p) / 2){
        pre = p;
        p = p->next;
        count++;
    }
    if (pre != NULL && p != NULL){
        pre->next = NULL;
        HLink q = p->next;
        p->next = pre;
        while (q != NULL){
            q->next = p;
            pre = q;
            q = q->next;
        }
        pre->next = NULL;
    }
}

//函数void SortPriceL(HLink &H)，按照客房（入住价格，客房名称）升序排序；
void SortPriceL(HLink &H){
    HLink p, q, r;
    p = H->next;
    while (p != NULL){
        q = p->next;
        r = p;
        while (q != NULL){
            if (strcmp(q->roomN, r->roomN) > 0 || (strcmp(q->roomN, r->roomN) == 0 && q->PriceL < r->PriceL)){
                r = q;
            }
            q = q->next;
        }
        if (r != H){
            int tempBeds = r->Beds;
            char *tempState = strdup(r->State);
            float tempPriceL = r->PriceL;
            strcpy(r->State, H->State);
            strcpy(H->State, tempState);
            r->PriceL = H->PriceL;
            H->PriceL = tempPriceL;
            r->Beds = H->Beds;
            H->Beds = tempBeds;
        }
        p = q;
    }
}


//函数void upBed(HLink &H,int beds)，创建一个【床位数为beds的新结点】（还需输入：客房名称、标准价格等信息），使链表的形态为：【头结点】->【床位数>beds的结点】->【床位数为beds的新结点】->【床位数<=beds的结点】，要求【超过beds的结点】和【不超过beds的结点】这两段链表中的结点保持原来的前后相对顺序；
void upBed(HLink &H,int beds){
    HLink p = H;
    while (p->next != NULL && p->next->Beds > beds){
        p = p->next;
    }
    HLink new_node = (HLink)malloc(sizeof(Hotel));
    strcpy(new_node->roomN, p->next->roomN);
    new_node->PriceL = p->next->PriceL;
    new_node->Price = p->next->Price;
    //new_node->State = "free";
    strcpy(new_node->State,"free");
    new_node->Beds = beds;
    strcpy(new_node->next->State, p->next->State);
    strcpy(new_node->next->roomN, p->next->roomN);
    new_node->next->PriceL = p->next->PriceL;
    new_node->next->Price = p->next->Price;
    new_node->next->Beds = p->next->Beds;
    p->next->Beds = beds;
    p->next = new_node;
}

//实现函数void Merge(HLink &H1, HLink &H2)，将两个按入住价格非递减排序的客房记录单合并为一个按入住价格非递增排序的客房记录单；要求算法的时间复杂度不超过两个链表的长度之和O(m+n)；
void Merge(HLink &H1, HLink &H2){
    HLink p = H1->next;
    while (p != NULL && p->next != NULL){
        if (strcmp(p->State, "free") == 0){
            H1->next = p->next;
            free(p);
            p = H1->next;
        }else{
            p = p->next;
        }
    }
    if (p != NULL && strcmp(p->State, "free") == 0){
        H1->next = NULL;
    }
    HLink q = H2->next;
    while (q != NULL && q->next != NULL){
        if (strcmp(q->State, "free") == 0){
            H2->next = q->next;
            free(q);
            q = H2->next;
        }else{
            q = q->next;
        }
    }
    if (q != NULL && strcmp(q->State, "free") == 0){
        H2->next = NULL;
    }
    HLink r = H1->next;
    HLink s = H2->next;
    while (r != NULL && s != NULL){
        if (r->PriceL > s->PriceL){
            H2->next = s;
            s->next = r;
            r = H1->next;
            s = H2->next;
        }else{
            H1->next = s;
            s->next = r;
            r = H1->next;
            s = H2->next;
        }
    }
    if (r != NULL){
        H2->next = r;
    }else{
        H1->next = s;
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
    HLink H_Linklist=NULL;
    Build(H_Linklist);

}
