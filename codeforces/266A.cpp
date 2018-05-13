#include <cstdio>

int main()
{
	int n;
	char str[51];

	scanf("%d", &n);
	scanf("%s", str);

	int count = 0;
	for(int i = 0; i < n; i++)
	for(int j = 1; i + j <= n; j++)
		if(str[i] == str[i + j]) count++;
		else
		{
			i += j - 1;
			break;
		}
	
	printf("%d\n", count);

	return 0;
}

