// 6828 - Help cupid

#include <cstdio>
#include <cstring>
#include <algorithm>

inline int distant(const int & i, const int & j)
{
	return std::min(abs(i - j), 24 - abs(i - j));
}

int main()
{
	int n, i, j, t;
	int hr[24], T[24], dif[24];
	int a, b;

	while(scanf("%d", &n) != EOF)
	{
		memset(hr, 0, sizeof(hr));

		for(i = 0; i < n; ++i)
		{
			scanf("%d", &t);
			hr[t + 11]++;
		}

		t = 0;
		for(i = 0; i < 24; ++i)
			if(hr[i] & 1) T[t++] = i;

		dif[0] = distant(T[0], T[t - 1]);

		for(i = 1; i < t; ++i)
			dif[i] = distant(T[i], T[i - 1]);

		a = b = 0;
		for(i = 0; i < t; i += 2)
		{
			a += dif[i];
			b += dif[i + 1];
		}

		printf("%d\n", a < b ? a : b);
	}
	return 0;
}
