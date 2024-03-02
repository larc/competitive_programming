// 11402 - Ahoy, Pirates!

#include <cstdio>

#define N 1024000

#define left(i) i << 1
#define right(i) (i << 1) + 1
#define M ((L + R) >> 1)

char land[N];
int tree[N << 3];		// Buccaner count
char tree_op[N << 3];	// lazy (0, F, E, I) operations

void build(const int n, const int L, const int R)
{
	tree_op[n] = 0;

	if(L == R)
	{
		tree[n] = land[L];
		return;
	}

	build(left(n), L, M);
	build(right(n), M + 1, R);

	tree[n] = tree[left(n)] + tree[right(n)];
}

void update(const int n, const int L, const int R, const char op)
{
	if(op == 'I')
	{
		if(tree_op[n] == 'F') update(n, L, R, 'E');
		else if(tree_op[n] == 'E') update(n, L, R, 'F');
		else
		{
			tree[n] = R - L + 1 - tree[n];
			if(tree_op[n] == 'I') tree_op[n] = 0;
			else tree_op[n] = 'I';
		}

		return;
	}

	if(op == 'F') tree[n] = R - L + 1;
	if(op == 'E') tree[n] = 0;

	tree_op[n] = op;
}

void update(const int n, const int L, const int R, const int a, const int b, const char op)
{
	if(a > R || b < L) return;

	if(tree_op[n] && L != R)
	{
		update(left(n), L, M, tree_op[n]);
		update(right(n), M + 1, R, tree_op[n]);
		tree_op[n] = 0;
	}

	if(a <= L && R <= b)
	{
		update(n, L, R, op);
		return;
	}

	update(left(n), L, M, a, b, op);
	update(right(n), M + 1, R, a, b, op);

	tree[n] = tree[left(n)] + tree[right(n)];
}

int query(const int n, const int L, const int R, const int a, const int b)
{
	if(a > R || b < L) return 0;

	if(a <= L && R <= b) return tree[n];

	if(tree_op[n] && L != R)
	{
		update(left(n), L, M, tree_op[n]);
		update(right(n), M + 1, R, tree_op[n]);
		tree_op[n] = 0;
	}

	int l = query(left(n), L, M, a, b);
	int r = query(right(n), M + 1, R, a, b);

	return l + r;
}

int main()
{
	int n_cases, n, m, a, b, q;
	char str[51];

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; ++c)
	{
		n = 0;

		scanf("%d", &m);
		while(m--)
		{
			scanf("%d", &q);
			scanf("%s", str);

			while(q--)
			{
				for(int i = 0; str[i]; ++i)
					land[n++] = str[i] - '0';
			}
		}

		build(1, 0, n - 1);		// build segment tree

		q = 1;
		printf("Case %d:\n", c);

		scanf("%d", &m);
		while(m--)
		{
			scanf(" %c %d %d", str, &a, &b);
			if(*str == 'S')
				printf("Q%d: %d\n", q++, query(1, 0, n - 1, a, b));
			else
				update(1, 0, n - 1, a, b, *str);
		}
	}

	return 0;
}

