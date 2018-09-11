#include <cstdio>

int main()
{
	int w;
	scanf("%d", &w);

	if(w > 2 && !(w & 1)) printf("YES\n");
	else printf("NO\n");

	return 0;
}

