#include <cstdio>

int main()
{
	int n, m, i, j;
	char str[102], a, b;

	scanf("%d %d", &n, &m);
	scanf("%s", str + 1);

	while(m--)
	{
		scanf("%d %d %c %c", &i, &j, &a, &b);
		while(i <= j) if(str[i++] == a) str[i - 1] = b;
	}
	
	printf("%s\n", str + 1);

	return 0;
}

