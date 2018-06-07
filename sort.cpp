#include<vector>
#include<iostream>

using namespace std;

void InsertSort(int arr[], int len);
void InsertSort2(int arr[],int n);
void InsertSort3(vector<int> &num);


void InsertSort(int arr[], int len)
{
    int i, j;
    int temp;
    for (i = 1; i < len; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}
void InsertSort2(int arr[],int n)
{
    for (int i =1; i <= n; ++i)
    {
        for(int j = i; j > 0; --j)
        {
            if(arr[j] < arr[j -1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
void InsertSort3(vector<int> &num)
{
    for(int i = 1; i < num.size(); ++i)
    {
        for(int j = i; j > 0; --j)
        {
            if(num[j] < num[j - 1])
            {
                int temp = num[j];
                num[j] = num[j-1];
                num[j-1] = temp;
            }
        }
    }
}


int main()
{
    vector[int] a = {4,5,6,3,1,0,34,12,45,8,2};
    InsertSort3(a);
    for(int i=0; i<11; ++i) cout<<a[i]<<' ';
}
