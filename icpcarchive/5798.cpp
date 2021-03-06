// 5798 - Jupiter Attacks!

#include <cstdio>
#include <cstring>

#define L 100001

int p, l;
int B[L], f[L], ft[L];

void adjust(int i, const int & v)
{
	f[i] = (1ll * f[i] + v) % p;

	while(i <= l)
	{
		ft[i] = (1ll * ft[i] + v) % p;
		i += i & -i;
	}
}

long long rsq(int i)
{
	long long r = 0;

	while(i)
	{
		r = (r + ft[i]) % p;
		i -= i & -i;
	}

	return r;
}

int pow(const int & b, const int & x)
{
	if(!x) return 1;

	long long r = pow(b, x >> 1);
	if(x & 1) return (((r * r) % p ) * b ) % p;
	return (r * r) % p;
}

int main()
{
	long long b;
	int n, i, j;
	char str[2];
	
	while(scanf("%lld %d %d %d", &b, &p, &l, &n) && b)
	{
		memset(f, 0, sizeof(f));
		memset(ft, 0, sizeof(ft));

		B[0] = 1;
		for(int i = 1; i < l; ++i)
			B[i] = (b * B[i - 1]) % p;

		while(n--)
		{
			scanf("%s %d %d", str, &i, &j);
			if(str[0] == 'E') adjust(i, (1ll * B[l - i] * j) % p - f[i] + p);
			else
			{
				b = (rsq(j) - rsq(i - 1) + p) % p;
				printf("%lld\n", (b * pow(B[l - j], p - 2)) % p);
			}
		}

		printf("-\n");
	}

	return 0;
}

