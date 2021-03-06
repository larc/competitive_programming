#include <cstdio>

int main()
{
	int n, m;
	char str[101];

	scanf("%d", &n);
	scanf("%s", str);

	n -= 2; m = 0;
	for(int i = 0; i < n; ++i)
	{
		if(str[i] == 'x' && str[i + 1] == 'x' && str[i + 2] == 'x')
			m++;
	}
	
	printf("%d\n", m);

	return 0;
}

