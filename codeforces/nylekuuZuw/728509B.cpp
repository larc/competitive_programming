#include <cstdio>
#include <cstring>
#include <queue>


int main()
{
	int B[1'000'001] = {};
	int n, d, k, a, b;
	scanf("%d %d %d", &n, &d, &k);

	while(k--)
	{
		scanf("%d %d", &a, &b);
		B[a] = b;
	}

	int dist[1'000'001];
	memset(dist, -1, sizeof(dist));

	std::queue<int> q;
	q.push(1);
	dist[1] = 0;

	while(!q.empty())
	{
		a = q.front();
		q.pop();

		if(a == n) break;

		b = a + d;
		for(int i = a + 1; i <= b; ++i)
		{
			k = B[i] ? B[i] : i;
			if(dist[k] != -1) continue;
			dist[k] = dist[a] + 1;
			q.push(k);
		}
	}

	printf("%d\n", dist[n]);

	return 0;
}

