// 12086 - Potentiometers

#include <cstdio>
#include <cstring>

#define N 200001
#define ls_one(i) (i & (-i))

// Fenwick Tree
int ft[N];
int n;

void adjust(int k, int v)
{
	while(k <= n)
	{
		ft[k] += v;
		k += ls_one(k);
	}
}

int rsq(int b)
{
	if(!b) return 0;

	return ft[b] + rsq(b - ls_one(b));
}

int main()
{
	int a, b, n_cases = 1;
	int potmeter[N];
	char str[4];

	scanf("%d", &n);
	while(n)
	{
		memset(ft, 0, sizeof(ft));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", potmeter + i);
			adjust(i, potmeter[i]);
		}

		printf("Case %d:\n", n_cases++);
		while(scanf("%s", str), str[0] != 'E')
		{
			scanf("%d %d", &a, &b);
			if(str[0] == 'S')
			{
				adjust(a, b - potmeter[a]);
				potmeter[a] = b;
			}
			else printf("%d\n", rsq(b) - rsq(a - 1));
		}

		scanf("%d", &n);
		if(n) putchar('\n');
	}

	return 0;
}

