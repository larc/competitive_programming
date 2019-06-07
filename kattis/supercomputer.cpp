#include <cstdio>
#include <cstring>

#define N 1000001

int mem[N];
int ft[N], n;

void add(int i, const int & v)
{
	while(i <= n)
	{
		ft[i] += v;
		i += (i & -i);
	}
}

int rsq(int i)
{
	int r = 0;

	while(i)
	{
		r += ft[i];
		i -= (i & -i);
	}

	return r;
}

int main()
{
	char q;
	int i, j, k;

	memset(ft, 0, sizeof(ft));
	memset(mem, 0, sizeof(mem));

	scanf("%d %d", &n, &k);
	while(k--)
	{
		scanf(" %c %d", &q, &i);

		if(q == 'F')
		{
			add(i, !mem[i] - mem[i]);
			mem[i] = !mem[i];
		}
		else
		{
			scanf("%d", &j);
			printf("%d\n", rsq(j) - rsq(i - 1));
		}
	}


	return 0;
}

