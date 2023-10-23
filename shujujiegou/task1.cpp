#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// #include<bits/stdc++.h>
#include <conio.h>
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
Hotel *Build(char filename[255])
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
    printf("\n");
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
    p->next = NULL;
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
    HLink p1 = H, p2 = H->next, p3;
    while (p2->next != NULL)
    {
        if (p2->next == NULL)
        {
            break;
        }
        else if (p2->next->next == NULL)
        {
            break;
        }
        else
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
    }
    p1 = p1->next;
    p2 = p1->next->next;

    p1->next->next = NULL;

    while (p2 != NULL)
    {
        HLink temp = p2->next;
        p3 = p1->next;
        p1->next = p2;
        p2->next = p3;
        p2 = temp;
    }
}

// 函数void SortPriceL(HLink &H)，按照客房（入住价格，客房名称）升序排序；冒泡
void SortPriceL(HLink &H)
{
    int pd = 1;
    while (pd != 0)
    {
        pd = 0;
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
    new_node->Beds = beds;
    new_node->PriceL = new_node->Price * 0.8;
    strcpy(new_node->State, "free");
    new_node->next = NULL;
    HLink Hq = (HLink)malloc(sizeof(Hotel));
    Hq->next = NULL;
    HLink q = Hq;
    while (p->next != NULL)
    {
        if (p->next->Beds <= new_node->Beds)
        {
            HLink temp = p->next->next;
            q->next = p->next;

            q->next->next = NULL;
            p->next = temp;
            q = q->next;
        }
        else
        {
            p = p->next;
        }
    }
    p->next = new_node;
    new_node->next = Hq->next;
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
        if (r == NULL)
        {
            HLink temp1 = H1->next, temp2 = s->next;
            H1->next = s;
            s->next = temp1;
            s = temp2;
        }
        else if (s == NULL)
        {
            HLink temp1 = H1->next, temp2 = r->next;
            H1->next = r;
            r->next = temp1;
            r = temp2;
        }
        else if (r->PriceL > s->PriceL) // 取s
        {
            HLink temp1 = H1->next, temp2 = s->next;
            H1->next = s;
            s->next = temp1;
            s = temp2;
        }
        else
        {
            HLink temp1 = H1->next, temp2 = r->next;
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

void Menu()
{
    printf("1.导入酒店数据\n");
    printf("2.查看酒店数据\n");
    printf("3.将床位数为beds的客房入住状态改为state\n");
    printf("4.查找房间\n");
    printf("5.将该链表中未入住的客房入住价格均加价20%\n");
    printf("6.找出价格最高的房间并删除\n");
    printf("7.单链表中倒数第k个结点之后的所有结点移到头结点后面\n");
    printf("8.将单链表的正中间位置结点之后的全部结点倒置\n");
    printf("9.按照客房（入住价格，客房名称）升序排序\n");
    printf("10.创建一个【床位数为beds的新结点】\n");
    printf("11.将两个按入住价格非递减排序的客房记录单合并为一个按入住价格非递增排序的客房记录单\n");
    printf("12.退出\n");
    printf("请选择:\n");
}
// 密码显示星号
void passwordstar(char *password)
{
    int i = 0;        // 记录密码长度
    char buff = '\0'; // 用于实现密码隐式输入
    while ((buff = getch()) != '\r')
    {
        if (buff == '\b' && i != 0)
        {
            i--;
            printf("\b \b");
        }
        else if (buff != '\b')
        {
            password[i++] = buff;
            putchar('*');
        }
    }
    password[i] = '\0';
    return;
}

// 密码加密
void cryptopassword(char *password, char *cryptopass)
{
    int count = strlen(password);
    int i = 0;
    for (i = 0; i < count; i++)
    {
        cryptopass[i] = password[i] + i + 6; // 简单加密，按照ascii表向后偏移i+6个位置
    }
    cryptopass[i] = '\0';
    return;
}
int login()
{ //(0、学生 1、老师)
    FILE *fp;
    int sta = -1;
    int command;
    // fp = fopen("ID.dat", "a+");
    char ID[255], passWord[255], cryptopass[255]; // cryptopass[255]为加密后的字符串
    while (1)
    {
        printf("---------------------------------\n");
        printf("1.登录系统\n");
        printf("2.新建用户\n");
        printf("0.退出\n");
        printf("---------------------------------\n");
        printf("请选择：");
        scanf("%d", &command);
        printf("\n");
        switch (command)
        {
        case 1:
            printf("-------------账户登录-------------\n");
            if ((fp = fopen("ID.dat", "r")) == NULL)
            {
                printf("文件打开失败！\n");
            }
            printf("账户名：");
            scanf("%s", &ID);
            printf("密  码：");
            // scanf("%s", &passWord);
            passwordstar(passWord);
            cryptopassword(passWord, cryptopass); // 加密passWord ,结果通过指针传到crytopass
            sta = -1;                             // 设立一个标志。学生0，老师1，其它-1
            while (sta == -1)
            {
                if (feof(fp))
                    break;
                char ID_[255], passWord_[255];
                int sta_;
                fscanf(fp, "%s%s%d", &ID_, &passWord_, &sta_);
                if (strcmp(ID, ID_) == 0 && strcmp(cryptopass, passWord_) == 0) // 使用加密后的字符串和密码文件比较
                    sta = sta_;
            }
            fclose(fp);
            if (sta == -1)
            {
                printf("\n");
                printf("账户名或密码错误\n");
                printf("--------------------------------");
            }
            else
            {
                fclose(fp);
                if (sta == 0)
                {
                    printf("欢迎%s同学登录！\n\n", ID);
                }
                else
                    printf("欢迎%s老师登录！\n\n", ID);
                return sta;
            }
            break;

        case 2:
            printf("------------创建账户-------------\n");
            printf("\n");
            fp = fopen("ID.dat", "a+");
            printf("账户名：");
            scanf("%s", ID);
            printf("密  码：");
            passwordstar(passWord);
            cryptopassword(passWord, cryptopass);
            printf("\n");
            printf("您的身份(0、学生 1、老师)：");
            scanf("%d", &sta);
            fprintf(fp, "%s %s %d\n", ID, cryptopass, sta); // 将加密后的密码存到文件
            fclose(fp);
            break;
        case 0:
            exit(0);
        default: // 若输出错误的序号，则跳转至重新输出
            printf("输入错误，请重新输入！\n");
            break;
        }
    }
}

int main()
{
    int num;
    int command;
    HLink H_Linklist[10] = {NULL};
    // H_Linklist[1]=Build("Hotel1.txt");
    // H_Linklist[2]=Build("Hotel2.txt");
    printf("请登录\n");
    int STA = login();
    command = 0;
    while (command != 12)
    {
        Menu();
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            printf("请输入文件名：");
            char filename[255];
            scanf("%s", filename);
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            H_Linklist[num] = Build(filename);
            Exp(H_Linklist[num]);
            break;
        case 2:
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            Exp(H_Linklist[num]);
            break;
        case 3:
        {
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            printf("请选择床位数:");
            int beds;
            scanf("%d", &beds);
            printf("请输入状态:(空闲(free)、入住(in)、预订(reserve))");
            char state[10];
            scanf("%s", state);
            updateH(H_Linklist[num], beds, state);
            Exp(H_Linklist[num]);
        }
        break;
        case 4:
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            char room[255];
            printf("请选择房间号:");
            scanf("%s", room);
            num = Find(H_Linklist[num], room);
            printf("在列表中的第%d个\n", num);
            break;
        case 5:
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            Add(H_Linklist[num]);
            Exp(H_Linklist[num]);
            break;
        case 6:
        {
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            HLink firsth = (HLink)malloc(sizeof(Hotel));
            firsth->next = FirstH(H_Linklist[num]);
            printf("入住价格最高为：\n");
            Exp(firsth);
            printf("删除后：\n");
            Exp(H_Linklist[num]);
        }
        break;
        case 7:
        {
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            int k;
            printf("请输入k:");
            scanf("%d", &k);
            MoveK1(H_Linklist[num], k);
            Exp(H_Linklist[num]);
        }
        break;
        case 8:
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            ReverseN2(H_Linklist[num]);
            Exp(H_Linklist[num]);
            break;
        case 9:
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            SortPriceL(H_Linklist[num]);
            Exp(H_Linklist[num]);
            break;
        case 10:
        {
            int beds;
            printf("请选择编号：(0~9):");
            scanf("%d", &num);
            printf("请输入床位数\n");
            scanf("%d", &beds);
            upBed(H_Linklist[num], beds);
            Exp(H_Linklist[num]);
            break;
        }
        case 11:
        {
            int num1, num2;
            printf("请选择两个编号：(0~9):");
            scanf("%d%d", &num1, &num2);
            Merge(H_Linklist[num1], H_Linklist[num2]);
            Exp(H_Linklist[num1]);
            break;
        }
        case 12:
            break;
        default:
            printf("不是可用功能\n");
            break;
        }
    }
}
