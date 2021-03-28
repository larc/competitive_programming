#include <cstdio>

#define N 1000001

using namespace std;

int main()
{
	char str[N];
	int q, n, i, j;
	long long k;

	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %lld", &n, &k);
		scanf("%s", str);

		i = 0;
		while(str[i] == '0') i++;

		j = i + 1;

		while(k)
		{
			while(str[j] == '1') j++;

			if(j >= n) break;

			if(j - i <= k)
			{
				k -= j - i;
			}
			else
			{
				i = j - k;
				k = 0;
			}

			str[i] = '0';
			str[j] = '1';
			i++;
		}

		printf("%s\n", str);
	}

	return 0;
}

