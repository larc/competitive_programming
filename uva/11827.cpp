// 11827 - Maximum GCD

#include <cstdio>
#include <algorithm>

#define N 100

int gcd(const int a, const int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}

int main()
{
	char line[1024];
	int num[N];
	int n, m, max, offset, o;


	scanf("%d", &n);
	fgets(line, 1024, stdin);

	while(n--)
	{
		fgets(line, 1024, stdin);

		m = 0;
		offset = 0;
		while(sscanf(line + offset, "%d%n", &num[m], &o) != EOF) { offset += o; m++; }

		max = 0;
		for(int i = 0; i < m; ++i)
		for(int j = i + 1; j < m; ++j)
			max = std::max(max, gcd(num[i], num[j]));

		printf("%d\n", max);
	}
	return 0;
}

