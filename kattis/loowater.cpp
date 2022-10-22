#include <cstdio>
#include <algorithm>

#define N 20000

int head[N];
int knight[N];

int main()
{
	int n, m, i, j, p;
	while(scanf("%d %d", &n, &m), n && m)
	{
		i = j = 0;
		while(i < n) scanf("%d", head + i++);
		while(j < m) scanf("%d", knight + j++);

		std::sort(head, head + n);
		std::sort(knight, knight + m);

		p = i = j = 0;
		while(i < n && j < m)
		{
			if(head[i] <= knight[j])
			{
				i++;
				p += knight[j++];
			}
			else j++;
		}

		if(i == n) printf("%d\n", p);
		else printf("Loowater is doomed!\n");
	}

	return 0;
}

