// 10172 - The Lonesome Cargo Distributor

#include <cstdio>
#include <stack>
#include <queue>

#define N 100

int main()
{
	int n_cases, time, n, s, q, m, x, cargoes;
	std::stack<int> carrier;
	std::queue<int> station[N];

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		cargoes = 0;

		scanf("%d %d %d", &n, &s, &q);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			cargoes += m;

			while(m--)
			{
				scanf("%d", &x);
				station[i].push(x - 1);
			}
		}

		m = 0; time = 0;
		while(cargoes)
		{
			// unloading
			while(!carrier.empty())
			{
				if(carrier.top() == m)			// platform A 
				{
					carrier.pop();
					time++;
					cargoes--;
				}
				else if(station[m].size() < q)	// platform B
				{
					station[m].push(carrier.top());
					carrier.pop();
					time++;
				}
				else break;
			}

			// loading
			while(!station[m].empty() && carrier.size() < s)
			{
				carrier.push(station[m].front());
				station[m].pop();
				time++;
			}

			m = (m + 1) % n;
			time += 2;
		}

		printf("%d\n", time - 2);
	}

	return 0;
}

