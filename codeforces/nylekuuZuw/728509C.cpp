#include <cstdio>
#include <cstring>
#include <queue>


int to_int(char * str)
{
	int n = 0;
	while(*str)
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	return n;
}

int main()
{
	int dist[10000];
	int w, k, a, b;
	char s[5], t[5], c[5];

	memset(dist, -1, sizeof(dist));

	scanf("%d %s %s %d", &w, s, t, &k);
	while(k--)
	{
		scanf("%s", c);
		dist[to_int(c)] = -2;	// codigo prohibido
	}

	a = to_int(s);
	b = to_int(t);
	std::queue<int> q;
	if(dist[a] == -1)
	{
		q.push(a);
		dist[a] = 0;
	}

	while(!q.empty())
	{
		a = q.front();
		q.pop();

		if(a == b) break;

		k = 1;
		for(int i = 0; i < w; ++i)
		{
			const int digit = (a % (k * 10)) / k;
			const int prev = a - (digit > 0 ? k : -9 * k);
			const int next = a + (digit < 9 ? k : -9 * k);
			for(const int neig: {prev, next})
				if(dist[neig] == -1)
				{
					dist[neig] = dist[a] + 1;
					q.push(neig);
				}
			k *= 10;
		}
	}

	printf("%d\n", dist[b] < 0 ? -1 : dist[b]);

	return 0;
}

