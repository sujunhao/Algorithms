#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#define MAX 1000
#define EE 2.71828182846
#define PI 3.14159265359
using namespace std;

//t%2,t/2
//n=t*2^k+m恒成立， 其中m表示由bi栈内存的[k,k-1,''',1]表示的二进制数
//可用数学归纳法证 《算法引论》2-12
stack<char> bi;
void Convert_to_Binary(int t)
{
    while (t>0){
        bi.push(t%2 ? '1' : '0');
        t/=2;
    }

    while (!bi.empty())
    {
        putchar(bi.top());
        bi.pop();
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Convert_to_Binary(n);

    return 0;
}
