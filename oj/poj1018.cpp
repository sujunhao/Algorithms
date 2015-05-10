#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
#define MAX 100
#define EE 2.71828182846
#define PI 3.14159265359
using namespace std;

int dp[100000];

int main()
{
    int T, n, k, b[MAX], p[MAX];
    scanf("%d", &T);
    while (T--)
    {
    	scanf("%d", &n);
    	memset(dp, -1, sizeof(dp));
    	int mx=-1;
    	for (int i=0; i<n; i++)
    	{
    		scanf("%d", &k);
    		for (int j=0; j<k; j++)
    		{
    			scanf("%d%d", &b[j], &p[j]);
    			mx=max(mx, b[j]);
    		}
    		if (i==0) 
    		{
    			for (int j=0; j<k; j++)
    			{
    				if (dp[b[j]]==-1)
    					dp[b[j]]=p[j];
    				else dp[b[j]]=min(dp[b[j]], p[j]);
    			}
    		}
    		for (int m=1; m<=mx; m++)
    		{
    			if (dp[m]==-1) continue;
    			for (int j=0; j<k; j++)
    			{
    				int tb=min(b[j], m);
    				if (dp[tb]==-1) dp[tb]=dp[m]+p[j];
    				else
    				{
    					dp[tb]=min(dp[tb], dp[m]+p[j]);
    				}
    			}
    		}
    	}
    	double tmp=0;
    	for (int i=1; i<=mx; i++)
    	{
    		if (dp[i]!=-1)
    			tmp=max(tmp, (1.0)*i/dp[i]);
    	}
    	printf("%.3lf\n", tmp);
    	
    }
    
    return 0;
}
