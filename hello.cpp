#include <cstdio>

void myswap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}
int main()
{
	int a, b;
	a = 10;
	b = 2;
	scanf("%d%d", &a, &b);
	myswap(a, b);
	printf("%d %d\n", a, b);
	return 0;
}