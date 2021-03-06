#include <cstdio>
#include <cstring>
#include <cmath>

bool is_jolly(bool * seq, int n)
{
	while(--n)
		if(!seq[n]) return 0;
	
	return 1;
}

int main()
{
	int n, a, b;
	bool seq[3000];

	while(scanf("%d", &n) != EOF)
	{
		memset(seq, 0, sizeof(bool) * n);
		
		scanf("%d", &a);
		for(int i = 1; i < n; ++i)
		{
			scanf("%d", &b);
			a = std::abs(a - b);
			if(a < n) seq[a] = 1;
			a = b;
		}

		if(is_jolly(seq, n)) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}

