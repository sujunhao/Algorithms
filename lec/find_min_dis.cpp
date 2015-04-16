#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <stack>
#include <cmath>
#define MAX 10000
#define EE 2.71828182846
#define PI 3.14159265359
#define ERROR -123
using namespace std;

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
int Select_kth(int X[], int l, int r, int k)
{
    int p=X[l];
    int pk=Partition(X, l, r)-l+1;
    if (pk==k) return p;
    if (pk>k) return Select_kth(X, l, l+pk-2, k);
    else return Select_kth(X, l+pk, r, k-pk);
}


//找X数组中最小间距，一维情况。
//排序后 以中位数为基点分2半，再分治
int find_min_dis(int X[], int l, int r, int n)
{
    if (n<=1) return 0;
    if (n==2) return X[r]-X[l];
    if (n==3) return min((X[r]-X[r-1]), (X[l+1]-X[l]));
    int k, k1, k2;
    k = Select_kth(X, l, r, n/2);
    swap(X[l], X[n/2]);
    Partition(X, l, r);
    //printf("%d %d\n", k, X[n/2]);
    k1 = find_min_dis(X, l, l+n/2, n/2+1);
    k2 = find_min_dis(X, l+n/2-1, r, n-n/2+1);
    return min(k1, k2);
}
int main()
{
    while (~scanf("%d", &n))
    {
        srand(time(0));
        for(int i=1; i<=n; i++)
        {
            X[i]=rand()%100000;
            //scanf("%d", &X[i]);
        }
        Quick_sort(X, 1, n);

        for (int i=1; i<=n; i++)
            printf("%d ", X[i]);
        puts(" ");
        int mm=12333;
        for (int i=2; i<=n; i++)
        {
            if (X[i]-X[i-1]<mm) mm=X[i]-X[i-1];
            printf("%d ", X[i]-X[i-1]);
        }
        puts(" ");

        printf("%d %d\n", find_min_dis(X, 1, n, n), mm);
    }
    return 0;
}
