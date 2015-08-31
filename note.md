
``` c++
//整数运算
8/5=0;

//数组copy   a -> b
#include <cstring>

memcpy(b, a, sizeof(a));
memcpy(b, a, sizeof(int)*k);


memset(a, 0, sizeof(a));

int first = 1;
for (int i=0; i<n; i++)
{
    if (first) first = 0;
    else printf(" ");
    printf("%d", f[i]);
}
printf('\n');



//find char in some pattern
char buffer[99];
char s[20];
int x, y, z;
gets(s);

sprintf(buffer, "%d%d%d", x, y, z);
int ok=1;
for (int i=0; i<strlen(buffer); i++)
if (strchr(s, buffer[i]) == NULL) ok = 0;

if (ok)
//not find other char in buffer

```