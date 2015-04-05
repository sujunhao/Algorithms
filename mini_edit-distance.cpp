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

char A[MAX], B[MAX], C[MAX][MAX];
//求最小改变距离 有3种改变
//分别为增 删 改 一个字符
//输入2字符串及对应长度 输出C[i][j]， 其中存的是A的前i个字符变成B前j个字符的最少次数
//动态规划   
//《算法引论》6.8序列比较
void Minimum_Edit_Distance(char A[],int  n,char B[],int  m)
{
    int x, y, z, f;
    memset(C, 0, sizeof(0));
    for (int i=0; i<=n; i++) C[i][0]=i;
    for (int i=1; i<=m; i++) C[0][i]=i;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            x = C[i-1][j]+1;//删掉A的最后一个字符
            y = C[i][j-1]+1;//删掉B的最后一个字符 （为A增加一个字符）
            if (A[i]==B[j]) z = C[i-1][j-1];    //若A[i]与B[j]匹配
            else z = C[i-1][j-1]+1;             //不匹配时把A[i]改为B[j]
            C[i][j]=min(x, min(y, z));
        }
    }
}
int main()
{
    gets(A);
    gets(B);
    Minimum_Edit_Distance(A, strlen(A), B, strlen(B));
    for (int i=0; i<=strlen(A); i++)
    {
        for (int j=0; j<=strlen(B); j++)
            printf("(%d,%d) %d  ", i, j, C[i][j]);
        puts(" ");
    }
    puts(" ");


    return 0;
}
