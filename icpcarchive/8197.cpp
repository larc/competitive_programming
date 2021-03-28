// 8197 - Jumping Frog
// ACM ICPC 2017 - South America

#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 100001
#define M 640 // aprox 2 * sqrt N

int rooks[N];
char str[N];		// input string
int n_div, D[M];	// divisors array

bool jump(const int & k, const int & n, const int & s)
{
	for(int i = s; i < n; i += k)
		if(str[i] == 'P') return 0;

	return 1;
}

bool jump(const int & k, const int & n)
{
	for(int i = 0; i < n && rooks[i] < k; ++i)
		if(jump(k, n, rooks[i]))
			return 1;

	return 0;
}

void divisors(const int & n)
{
	n_div = 0;

	int i;
	for(i = 2; i * i < n; ++i)
		if(!(n % i))
		{
			D[n_div++] = i;
			D[n_div++] = n / i;
		}

	if(i * i == n) D[n_div++] = i;
}

int main()
{
	int n, m;
	int gcd[N];
	int count;

	while(scanf("%s", str) != EOF)
	{
		m = n = 0;
		for(n = 0; str[n] != '\0'; ++n)
			if(str[n] == 'R')
				rooks[m++] = n;

		if(m == n) printf("%d\n", n - 1);
		else
		{
			memset(gcd, 0, sizeof(gcd));
			for(int i = 2; i < n; ++i)
				gcd[std::__gcd(i, n)]++;

			divisors(n);

			count = 0;
			for(int i = 0; i < n_div; ++i)
			{
				int & d = D[i];
				if(jump(d, n))
					count += gcd[d];
			}

			printf("%d\n", count);
		}
	}

	return 0;
}

