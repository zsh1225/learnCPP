#include <stdio.h>
 
// ��srcͳ���ַ�ch����,������
int strCount(const char* src, char ch = ' ')
{
    int i = -1, cnt = 0;
    while (src[++i])
        if (src[i] == ch)
            cnt++;
    return cnt;
}
 
int main()
{
    char p[100];
    // �������ո���Ŀ
    printf("1111111111111111111111111111111111111111111111\n");
    printf("input a string:");
    gets(p);
    printf("space count has %d.\n", strCount(p));
    return 0;
} 
