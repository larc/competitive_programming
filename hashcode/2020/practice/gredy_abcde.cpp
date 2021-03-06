#include <cstdio>
#include <stack>

#define N 100000

int main()
{
	int m, n;
	int S[N];

	std::stack<int> order;

	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", S + i);

	for(int i = n - 1; i >= 0; i--)
		if(m - S[i] >= 0)
		{
			m -= S[i];
			order.push(i);
		}
	
	printf("%lu\n", order.size());
	while(!order.empty())
	{
		printf("%d ", order.top());
		order.pop();
	}
	putchar('\n');

	return 0;
}

