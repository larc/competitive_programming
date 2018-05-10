#include <cstdio>

int main()
{
	char op[4];
	int x = 0;

	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", op);
		if(op[1] == '+') x++;
		else x--;
	}

	printf("%d\n", x);

	return 0;
}

