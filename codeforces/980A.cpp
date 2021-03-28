#include <cstdio>

int main()
{
	char str[128];
	scanf("%s", str);

	int n = 0, p = 0;
	while(str[n] != '\0')
		if(str[n++] == 'o') p++;

	if(p && n % p) printf("NO\n");
	else printf("YES\n");

	return 0;
}
