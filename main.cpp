#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#define MAX 1000
#define EE 2.71828182846
#define PI 3.14159265359
using namespace std;


int a[MAX], n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}

	int tail=a[0], tail_i=0, max=a[0], max_l=0, max_r=0;
	for (int i=1; i<n; i++)
	{
		if (a[i]>0) 
		{
			if (tail>0)
			{
				tail = a[i] + tail;
				if (tail >= max)
				{
					max = tail;
					max_l = tail_i;
					max_r = i;
				}
			}
			else 
			{
				tail = a[i];
				tail_i=i;
				if (tail >= max)
				{
					max = tail;
					max_l = tail_i;
					max_r = i;
				}
			}

		}
		else
		{
			if (tail>0)
			{
				tail += a[i];
			}
			else
			{
				tail = a[i];
				tail_i = i;
			}
		}
	}

	printf("%d\n", max);
    
    return 0;
}
