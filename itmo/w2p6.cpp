// Snowmen

#include <cstdio>

#define N 1000001

int clone[N];
int top[N];
unsigned long long mass[N];

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	int n, t, m;
	unsigned long long total = 0;
	clone[0] = top[0] = mass[0] = 0;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d %d\n", &t, &m);
		if(!top[t]) t = clone[t];
		if(!m) t = clone[t];

		clone[i] = t;
		top[i] = m;
		mass[i] = mass[t] + m;

		total += mass[i];
	}

	printf("%llu\n", total);

	return 0;
}

