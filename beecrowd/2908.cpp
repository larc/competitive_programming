// 2908 - Fantastic Beasts

#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 10
#define M 101

typedef long long llu_t;

int Z[N][M];		// zoo moves
int current[N];		// current i-beast zoo
int T[N][M];		// first time i-beast in j-zoo
int C[N];			// i-beast loop size
bool loop[N][M];	// (i,j) = 1 if j-zoo is in i-beast loop

// solve ax + bx = gcd(a, b);
llu_t extended_euclid(const llu_t & a, const llu_t & b, llu_t & x, llu_t & y)
{
	if(!b)
	{
		x = 1;
		y = 0;
		return a;
	}

	llu_t x1, y1;
	llu_t d = extended_euclid(b, a % b, x1, y1);

	x = y1;
	y = x1 - (a / b) * y1;

	return d;
}

llu_t gcd(const llu_t & a, const llu_t & b)
{
	return !b ? a : gcd(b, a % b);
}

llu_t lcm(const llu_t & a, const llu_t & b)
{
	return b * (a / gcd(a, b));
}

int main()
{
	int n, m, z;	// numbers beasts and zoos
	llu_t t, tmax, x, y, a, b, ta, tb, d;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
	for(int j = 0; j <= m; ++j)
		scanf("%d", Z[i] + j);

	memset(T, -1, sizeof(T));
	memset(loop, 0, sizeof(loop));

	tmax = 0;
	for(int i = 0; i < n; ++i)
	{
		t = 0;
		z = Z[i][0];
		while(T[i][z] < 0)
		{
			T[i][z] = t++;
			z = Z[i][z];
		}

		C[i] = t - T[i][z];
		if(t > tmax) tmax = t;

		do
		{
			loop[i][z] = 1;
			z = Z[i][z];
		}
		while(!loop[i][z]);
	}

	// if they will meet soon
	for(int i = 0; i < n; ++i)
		current[i] = Z[i][0];

	for(t = 0; t < tmax; ++t)
	{
		for(int i = 1; i < n; ++i)
			if(i == n - 1 && current[i] == current[i - 1])
			{
				printf("%d %lld\n", current[i], t);
				return 0;
			}
			else if(current[i] != current[i - 1])
				break;

		for(int i = 0; i < n; ++i)
			current[i] = Z[i][current[i]];
	}

	// if they will never meet or will meet in a long time
	z = 0;
	for(int j = 1; j <= m; ++j)
	{
		if(!loop[0][j]) continue;

		ta = T[0][j];
		a = C[0];

		for(int i = 1; i < n; ++i)
		{
			if(!loop[i][j])
			{
				ta = 0;
				break;
			}

			tb = T[i][j];
			b = C[i];

			// solve: tb + b * x = ta + a * y
			// solve: b * x - a * y = ta + tb

			if(ta < tb)
			{
				std::swap(ta, tb);
				std::swap(a, b);
			}

			// look for a tij closed to t
			tb += ((ta - tb) / b) * b;

			// solve b * x - a * y = gcd(b, -a), '-a' will affect the 'y' value
			d = extended_euclid(b, a, x, y);

			// (ta -  tb) must be a multiple of gcd(b, -a)
			if((ta - tb) % d)
			{
				ta = 0;
				break;
			}

			y *= (ta - tb) / d;

			d = b / gcd(a, b);

			if(y) // new meet time, check if the new meet time is in the past
				ta += y < 0 ? a * -y : ((y / d + 1) * d - y) * a;

			a = a * d;		// new loop size a = lcm(a, b)

		}

		if(ta && (!z || ta < t))
		{
			z = j;
			t = ta;
		}
	}

	if(!z) printf("*\n");
	else printf("%d %lld\n", z, t);

	return 0;
}

