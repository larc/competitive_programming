#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>

#define N 101

using namespace std;

int main()
{
	int q, n, P[N], pos[N], x, p, o;

	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", P + i);
			pos[P[i]] = i;
		}
		
		p = x = 1;
		while(p < n)
		{
			if(pos[x] == p)
			{
				x++; p++;
				continue;
			}

			while(pos[x] < p) x++;
		
			o = pos[x];
			for(int i = pos[x]; i > p; i--)
			{
				std::swap(P[i], P[i - 1]);
				pos[P[i]] = i;
			}
			pos[P[p]] = p;
			p = o;
		}

		for(int i = 1; i <= n; i++)
			printf("%d ", P[i]);
		putchar('\n');
	}

	return 0;
}

