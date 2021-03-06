// 12765 - Factorial Products

#include <cstdio>
#include <cstring>

int counter[10];
bool check()
{
	if(counter[2]) return 0;
	if(counter[3]) return 0;
	if(counter[5]) return 0;
	if(counter[7]) return 0;

	return 1;
}

int main()
{
	int n, m, p;
	
	while(scanf("%d %d", &n, &m), n && m)
	{
		memset(counter, 0, sizeof(counter));

		while(n--)
		{
			scanf("%d", &p);
			for(int i = 2; i <= p; ++i)
				switch(i)
				{
					case 4: counter[2] += 2; break;
					case 6: counter[2]++; counter[3]++; break;
					case 8: counter[2] += 3; break;
					case 9: counter[3] += 2; break;
					default: counter[i]++;
				}
		}

		while(m--)
		{
			scanf("%d", &p);
			for(int i = 2; i <= p; ++i)
				switch(i)
				{
					case 4: counter[2] -= 2; break;
					case 6: counter[2]--; counter[3]--; break;
					case 8: counter[2] -= 3; break;
					case 9: counter[3] -= 2; break;
					default: counter[i]--;
				}
		}
		
		if(check()) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

