#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	const int MOD = 1000000;
	int n, s = 0;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int f = 1;
		for (int j=1; j<=i; j++)
		{
			f  = f*j%MOD;
		}
		s = (s+f)%MOD;
	}
	printf("%d\n", s);
	printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
	// system("pause");
	return 0;
}