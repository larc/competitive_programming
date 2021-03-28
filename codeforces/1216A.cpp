#include <cstdio>

#define N 200001

int main()
{
	char str[N];
	int n, count;

	scanf("%d", &n);
	scanf("%s", str);

	count = 0;
	for(int i = 0; i < n; i += 2)
		if(str[i] == str[i + 1])
		{
			str[i] = !(str[i] - 'a') + 'a';
			count++;
		}

	printf("%d\n%s\n", count, str);

	return 0;
}

