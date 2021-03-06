// 624 - CD

#include <cstdio>
#include <cstring>

int num[20];
int seq[20];
int sum, tracks[20], size;

void sum_it_up(const int & n, const int & s, const int & p, int i)
{
	if(n == i)
	{
		if(s < sum || (s == sum && p > size))
		{
			sum = s;
			size = p;
			memcpy(tracks, seq, sizeof(int) * size);
		}

		return;
	}
	
	while(i < n)
		if(num[i] <= s)
		{
			seq[p] = num[i];
			sum_it_up(n, s - seq[p], p + 1, ++i);
		}
		else sum_it_up(n, s, p, ++i);
}

int main()
{
	int s, n;
	while(scanf("%d %d", &s, &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", num + i);
		
		sum = s;
		size = 0;

		sum_it_up(n, s, 0, 0);
		for(int i = 0; i < size; ++i)
			printf("%d ", tracks[i]);
		printf("sum:%d\n", s - sum);
	}

	return 0;
}

