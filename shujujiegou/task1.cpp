#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef struct HNode
{
    char roomN[7];      // 客房名称
    float Price;        // 标准价格
    float PriceL;       // 入住价格(默认值=标准价格*80%)
    int Beds;           // 床位数Beds
    char State[7];      // 入住状态(值域："空闲(free)"、"入住(in)"、"预订(reserve)"，默认值为"空闲")
    struct HNode *next; // 指针域
} Hotel, *HLink;

// 初始化函数
Hotel *Build(char filename[10])
{
    HLink head = (HLink)malloc(sizeof(Hotel));
    head->next = NULL;
    HLink pRear = head;
    HLink new_node = NULL;
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("文件打开失败！\n");
        return NULL;
    }
    while (!feof(fp))
    {
        HLink new_node = (HLink)malloc(sizeof(Hotel));
        fscanf(fp, "%s %f %d", new_node->roomN, &new_node->Price, &new_node->Beds);
        new_node->PriceL = new_node->Price * 0.8;
        strcpy(new_node->State, "free");
        new_node->next = NULL;
        pRear->next = new_node;
        pRear = new_node;
    }
    fclose(fp);
    return head;
}

// 实现输出客房信息函数void Exp(HLink H)，输出所有客房的客房名称、标准价格、入住价格、床位数、入住状态
void Exp(HLink &H)
{
    HLink p = H->next;
    while (p != NULL)
    {
        printf("%s%8.1f%8.1f%6d%8s\n", p->roomN, p->Price, p->PriceL, p->Beds, p->State);
        p = p->next;
    }
}

// 函数int Find(HLink &H, char *roomN)，查找房间名称为roomN的客房。
// 如果找到，则返回该客房在链表中的位置序号（>=1），否则返回0。提示：用strcmp()字符串比较函数；
int Find(HLink &H, char *roomN)
{
    HLink p = H->next;
    int i = 1;
    while (p != NULL && strcmp(p->roomN, roomN))
    {
        p = p->next;
        i++;
    }
    return p != NULL ? i : 0;
}

// 实现函数void updateH(HLink &H, int beds, char *state)，
//  将床位数为beds的客房入住状态改为state。提示：用strcpy()字符串拷贝函数；
void updateH(HLink &H, int beds, char *state)
{
    HLink p = H->next;
    while (p != NULL)
    {
        if (p->Beds == beds)
        {
            strcpy(p->State, state);
        }
        p = p->next;
    }
}

// 函数void Add(HLink &H)，将该链表中未入住的客房入住价格均加价20%；
void Add(HLink &H)
{
    HLink p = H->next;
    while (p != NULL)
    {
        if (!strcmp(p->State, "free"))
        {
            p->PriceL *= 1.2;
        }
        p = p->next;
    }
}

// 求出入住价格最高的客房函数HLink FirstH(HLink &H)，该函数内return语句返回入住价格最高的客房结点指针，返回前将该结点在链表中删除；
HLink FirstH(HLink &H)
{
    HLink p_pre = H; // 当前值的前一个
    HLink Highest_pre = H;
    while (p_pre->next != NULL)
    {
        if (p_pre->next->PriceL > Highest_pre->next->PriceL)
            Highest_pre = p_pre;
        p_pre = p_pre->next;
    }
    HLink p = Highest_pre->next;
    Highest_pre->next = Highest_pre->next->next;
    return p;
}

// 函数void MoveK1(HLink &H, int k)，将单链表中倒数第k个结点之后的所有结点移到头结点后面，注意：严禁采用先计算链表长度n再减k（即n-k）的方法；
void MoveK1(HLink &H, int k)
{ // 单链表中倒数第k个结点之后的所有结点移到头结点后面
    HLink p = H->next;
    HLink p_pre = p; // 倒数第k个节点的指针
    int n = 1;
    while (p->next != NULL && n <= k)
    { // 使p_pre和p间隔k
        p = p->next;
        n++;
    }
    if (p == NULL)
    { // 如果链表中没有k个节点，则直接返回
        printf("链表中没有足够的节点\n");
        return;
    }
    while (p->next != NULL)
    {
        p_pre = p_pre->next;
        p = p->next;
    }
    HLink temp = p_pre->next;
    p_pre->next = NULL;
    p->next = H->next;
    H->next = temp; 
}

// 函数void ReverseN2(HLink &H)，将单链表的正中间位置结点之后的全部结点倒置的功能，注意：严禁采用先计算链表长度n再除以2（即n/2）的方法；
void ReverseN2(HLink &H)
{
    HLink p = H;
    HLink pre = NULL;
    int count = 0;
    while (p != NULL && count < (p->next - p) / 2)
    {
        pre = p;
        p = p->next;
        count++;
    }
    if (pre != NULL && p != NULL)
    {
        pre->next = NULL;
        HLink q = p->next;
        p->next = pre;
        while (q != NULL)
        {
            q->next = p;
            pre = q;
            q = q->next;
        }
        pre->next = NULL;
    }
}

// 函数void SortPriceL(HLink &H)，按照客房（入住价格，客房名称）升序排序；插入排序
void SortPriceL(HLink &H)
{
    int pd = 1;
    while (pd != 0)
    {
        pd = 0;
        printf("lll\n");
        HLink p = H;
        while (p->next->next != NULL)
        {
            if (p->next->PriceL > p->next->next->Price)
            {
                HLink p1 = p->next, p2 = p->next->next->next;
                p->next = p->next->next;
                p->next->next = p1;
                p->next->next->next = p2;

                pd = 1;
            }
            else if (p->next->PriceL == p->next->next->PriceL && strcmp(p->next->roomN, p->next->next->roomN) > 0)
            {
                HLink p1 = p->next, p2 = p->next->next->next;
                p->next = p->next->next;
                p->next->next = p1;
                p->next->next->next = p2;

                pd = 1;
            }
            p = p->next;
        }
    }
}

// 函数void upBed(HLink &H,int beds)，创建一个【床位数为beds的新结点】（还需输入：客房名称、标准价格等信息），使链表的形态为：【头结点】->【床位数>beds的结点】->【床位数为beds的新结点】->【床位数<=beds的结点】，要求【超过beds的结点】和【不超过beds的结点】这两段链表中的结点保持原来的前后相对顺序；
void upBed(HLink &H, int beds)
{
    HLink p = H;
    HLink new_node = (HLink)malloc(sizeof(Hotel));
    printf("请输入客房名称、标准价格\n");
    scanf("%s %f", new_node->roomN, &new_node->Price);
    new_node->Beds=beds;
    new_node->PriceL = new_node->Price * 0.8;
    strcpy(new_node->State, "free");
    new_node->next = NULL;
    HLink Hq= (HLink)malloc(sizeof(Hotel));
    Hq->next=NULL;
    HLink q=Hq;
    while (p->next!=NULL)
    {
        if(p->next->Beds<=new_node->Beds){
            HLink temp=p->next->next;
            q->next=p->next;
            
            q->next->next=NULL;
            p->next=temp;
            q=q->next;
        }
        else {
            p=p->next;
        }
    }
    p->next=new_node;
    new_node->next=Hq->next;
    free(Hq);
    
}

// 实现函数void Merge(HLink &H1, HLink &H2)，将两个按入住价格非递减排序的客房记录单合并为一个按入住价格非递增排序的客房记录单；要求算法的时间复杂度不超过两个链表的长度之和O(m+n)；
void Merge(HLink &H1, HLink &H2)
{
    HLink r = H1->next;
    HLink s = H2->next;
    H1->next = NULL;
    while (r != NULL || s != NULL)
    {
        if(r==NULL){
            HLink temp1=H1->next,temp2=s->next;
            H1->next = s;
            s->next = temp1;
            s = temp2;
        }
        else if(s==NULL){
            HLink temp1=H1->next,temp2=r->next;
            H1->next = r;
            r->next = temp1;
            r = temp2;
        }
        else if (r->PriceL > s->PriceL)//取s
        {
            HLink temp1=H1->next,temp2=s->next;
            H1->next = s;
            s->next = temp1;
            s = temp2;
        }
        else
        {
            HLink temp1=H1->next,temp2=r->next;
            H1->next = r;
            r->next = temp1;
            r = temp2;
        }
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

void Menu(){
    printf("1.导入酒店数据\n");
    printf("2.查看酒店数据\n");
    printf("3.删除酒店数据\n");
    printf("4.查找房间\n");
    printf("1.添加房间\n");
    printf("2.按价格排序\n");
    printf("3.合并两个房间记录单\n");
    printf("4.释放内存\n");
    printf("5.退出\n");
}
int main()
{
    HLink H_Linklist[10] = {NULL};
    H_Linklist[1]=Build("Hotel1.txt");
    H_Linklist[2]=Build("Hotel2.txt");



}
