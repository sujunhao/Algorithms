#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <iostream>
#define maxn 100000
#define theM 1e-10
using namespace std;


char s[maxn], p[maxn];

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);

	while (scanf("%s%s",s, p)==2)
	{
		int m = strlen(s), n = strlen(p), f=0;
		if (m<n){
			swap(s, p);
			swap(m, n);
		}
		for (int i=0; i<m; i++)
		{
			int k = i, j=0;
			while (j<n)
			{
				if (k>=m || (k<m && j<n &&(s[k]-'0')+(p[j]-'0')<=3))
				{
					k++;
					j++;
				}
				else break;
			}
			// printf("%d %d\n", i, j);
			if (j==n)
			{
				printf("%d\n", max(i+j, m));
				f=1;
				break;
			}
		}
		if (f==0) printf("%d\n", m+n);
	}
	// printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
	// system("pause");
	return 0;
}