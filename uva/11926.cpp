// 11926 - Multitasking

#include <cstdio>
#include <cstring>

#define N 1000001

int main()
{
	int n, m, i, j;
	bool time[N], conflict;

	while(scanf("%d %d", &n, &m), n || m)
	{
		memset(time, 0, sizeof(time));
		conflict = 0;

		while(n--)
		{
			scanf("%d %d", &i, &j);
			while(!conflict && i < j)
			{
				if(time[i]) conflict = 1;
				else time[i] = 1;
				i++;
			}
		}

		while(m--)
		{
			scanf("%d %d %d", &i, &j, &n);
			while(!conflict && i < N)
			{
				for(int k = i; k < j && k < N; k++)
					if(time[k])
					{
						conflict = 1;
						break;
					}
					else time[k] = 1;

				i += n;
				j += n;
			}
		}

		if(conflict) printf("CONFLICT\n");
		else printf("NO CONFLICT\n");
	}

	return 0;
}

