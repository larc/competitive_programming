#include <cstdio>
#include <stack>
#include <map>

#define N 200001

int main()
{
	int seq[N];
	std::map<int, int> idx;
	int pred[N] = {};
	int lenght[N] = {};

	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", seq + i);
		
		idx[seq[i]] = i;
		lenght[i] = 1;

		if(idx[seq[i] - 1])
		{
			pred[i] = idx[seq[i] - 1];
			lenght[i] += lenght[idx[seq[i] - 1]];
		}
	}

	int m = 1;
	for(int i = 2; i <= n; ++i)
		if(lenght[i] > lenght[m]) m = i;

	printf("%d\n", lenght[m]);

	std::stack<int> s;
	while(m)
	{
		s.push(m);
		m = pred[m];
	}

	while(!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}

	printf("\n");

	return 0;
}

