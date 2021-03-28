#include <cstdio>
#include <map>
#include <string>

#define N 30001

int ft[N], n;

void adjust(int i, const int & val)
{
	while(i <= n)
	{
		ft[i] += val;
		i += i & -i;
	}
}

int rsq(int i)
{
	int r = 0;

	while(i)
	{
		r += ft[i];
		i -= i & -i;
	}

	return r;
}

int main()
{
	ft[0] = 0;

	std::map<std::string, int> M;
	char str[N][21];
	int n_cases, n_inv, j;

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			ft[i] = 0;
			scanf("%s", str[i]);
		}

		for(int i = 1; i <= n; ++i)
		{
			scanf("%s", *str);
			M[*str] = i;
		}

		n_inv = 0;
		for(int i = n; i > 0; i--)
		{
			j = M[str[i]];
			n_inv += rsq(j - 1);
			adjust(j, 1);
		}

		printf("%d\n", n_inv);

		M.clear();
	}

	return 0;
}

