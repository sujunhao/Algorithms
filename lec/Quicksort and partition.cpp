#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <stack>
#include <cmath>
#define MAX 1000
#define EE 2.71828182846
#define PI 3.14159265359
#define ERROR -123
using namespace std;
//quick_sort
//分治的思想，假设有一个k确定A[]中A[1 ~ k-1]<=A[k], A[k]<A[k+1 ~ n]
//分->Partition
//治->Q_s(l, m-1) Q_s(m+1, r)
//T(n)=2T(n/2)+O(n)   O(logn)
int X[MAX], n;
int Partition(int X[], int L, int R)
{
    int l=L, r=R, x=X[L];
    while (l<r)
    {
        while (l<=R && X[l]<=x) l++;
        while (r>=L && X[r]>x) r--;
        if (l<r) swap(X[l], X[r]);
    }
    swap(X[r], X[L]);
    return r;
}
void Quick_sort(int X[], int l, int r)
{
    if (l>=r) return;
    int mid;
    mid = Partition(X, l, r);
    Quick_sort(X, l, mid-1);
    Quick_sort(X, mid+1, r);

}


int main()
{
    scanf("%d", &n);
    srand(time(0));
    for(int i=1; i<=n; i++)
    {
        X[i]=rand()%100;
        //scanf("%d", &X[i]);
    }
    Quick_sort(X, 1, n);
    for (int i=1; i<=n; i++)
    {
        printf("%d ", X[i]);
    }
    return 0;
}
