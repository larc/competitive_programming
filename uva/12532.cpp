// 12532 - Interval Product

#include <cstdio>

#define N 100001
#define left(i) (i << 1)
#define right(i) (i << 1) + 1

int seq[N];
int prod[N << 2];

void build_st(const int & n, const int & i, const int & j)
{
	if(i == j)
	{
		prod[n] = seq[i];
		seq[i] = n;
		return;
	}
	
	int m = (i + j) >> 1;
	build_st(left(n), i, m);
	build_st(right(n), m + 1, j);

	prod[n] = (prod[left(n)] * prod[right(n)]) % 101;
}

void update_st(const int & n)
{
	if(!n) return;

	prod[n] = (prod[left(n)] * prod[right(n)]) % 101;
	update_st(n >> 1);
}

void update_st(const int & i, const int & v)
{
	prod[seq[i]] = v;
	update_st(seq[i] >> 1);
}

int rmq(const int & n, const int & L, const int & R, const int & i, const int & j)
{
	if(i > R || j < L) return 1;
	if(L >= i && R <= j) return prod[n];

	int m = (L + R) >> 1;
	return (rmq(left(n), L, m, i, j) * rmq(right(n), m + 1, R, i, j)) % 101;
}

char rmq(const int & a, const int & b, const int & n)
{
	int r = rmq(1, 1, n, a, b);
	return r ? (r < 0 ? '-' : '+') : '0';
}

int main()
{
	int n, k, a, b;
	char c;
	
	while(scanf("%d %d", &n, &k) != EOF)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d", &seq[i]);
		
		build_st(1, 1, n);
		while(k--)
		{
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'C') update_st(a, b);
			else putchar(rmq(a, b, n));
		}

		putchar('\n');
	}

	return 0;
}

