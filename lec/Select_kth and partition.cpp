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
int X[MAX], n, t;

//寻找第k大的数
//平均O(n)
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
int Select_kth(int X[], int l, int r, int k)
{
	int p=X[l];
	int pk=Partition(X, l, r)-l+1;
	if (pk==k) return p;
	if (pk>k) return Select_kth(X, l, l+pk-2, k);
	else return Select_kth(X, l+pk, r, k-pk);
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
    scanf("%d", &t);
    srand(time(0));
    for(int i=1; i<=n; i++)
    {
        X[i]=rand()%100;
        
    }
    printf("%d\n", Select_kth(X, 1, n, t));
    Quick_sort(X, 1, n);
    for (int i=1; i<=n; i++)
    {
        printf("%d ", X[i]);
    }
    printf("\n%d", X[t]);
    return 0;
}
