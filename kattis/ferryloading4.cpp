#include <cstdio>
#include <queue>

int main()
{
	char side[6];
	int i, c, n, m, length;

	scanf("%d", &c);
	while(c--)
	{
		std::queue<int> q[2];	// 0: left | 1: right
		scanf("%d %d", &n, &m);

		while(m--)
		{
			scanf("%d %s", &length, side);
			q[side[0] == 'r'].push(length);
		}

		n *= 100;
		m = 0;
		i = 0;
		while(1)
		{
			length = n;
			while(!q[i].empty() && q[i].front() <= length)
			{
				length -= q[i].front();
				q[i].pop();
			}

			if(length < n || !q[!i].empty())
			{
				m++;
				i = !i;
			}
			else break;
		}

		printf("%d\n", m);
	}

	return 0;
}

