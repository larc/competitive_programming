#include <cstdio>
#include <cstring>
#include <cmath>

bool is_jolly(bool * seq, int n)
{
	while(seq[--n]);
	return !n;
}

int main()
{
	int n, a, b;
	bool seq[3000];

	while(scanf("%d", &n) != EOF)
	{
		memset(seq, 0, sizeof(seq));

		scanf("%d", &a);
		for(int i = 1; i < n; ++i)
		{
			scanf("%d", &b);
			a = std::abs(a - b);
			if(a < n) seq[a] = 1;
			a = b;
		}

		printf("%s\n", is_jolly(seq, n) ? "Jolly" : "Not jolly");
	}

	return 0;
}

