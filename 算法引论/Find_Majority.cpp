#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#define MAX 10
#define EE 2.71828182846
#define PI 3.14159265359
#define ERROR -123
using namespace std;

int X[MAX];
//寻找出现次数大于n/2的数
//若x1!=x2 则删去2数不影响众数的地位
//不断删数直到剩一个再验证是否为众数
//O(n) 《算法引论》6.10查找众数
int Majority(int X[], int n)
{
    int c = X[1], m=1;
    for (int i=2; i<=n; i++)
    {
        if (m==0)
        {
            c = X[i];
            m=1;
        }
        else
        {
            if (c==X[i]) m++;
            else m--;
        }
    }
    if (m==0) return -1;
    int num=0;
    for (int i=1; i<=n; i++)
    {
        if (X[i]==c) num++;
    }
    if (num>n/2) return c;
    else return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &X[i]);
    printf("%d\n", Majority(X, n));

    return 0;
}
