#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int k, n;
	int b[50];
	int j, i = 0, s;
	while(scanf("%d", &n) != EOF && n)
	{
		i++;
		s = 0;
		for(j = 0; j < n; j++)
		{
			scanf("%d", b + j);
			s += b[j];
		}

		s /= n;
		k = 0;
		for(j = 0; j < n; j++)
			k += abs(b[j] - s);
		k >>= 1;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", i, k);
	}

	return 0;
}
