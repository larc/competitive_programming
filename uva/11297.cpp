// 11297 - Census

#include <cstdio>
#include <algorithm>
#include <utility>

#define N 500
#define M 2000

#define INF (1ll << 31) - 1

#define L(i) (i << 1) + 1
#define R(i) (i + 1) << 1
#define P(i) (i - 1) >> 1

typedef std::pair<int, int> pii;

int mat[N][N];
int ix[N][N];
int iy[N][N];
int min_st[M][M];
int max_st[M][M];
int size;

void init(const int & m, const int & r, const int & n, const int & ci, const int & cj)
{
	if(ci == cj)
	{
		min_st[m][n] = mat[r][ci];
		max_st[m][n] = mat[r][ci];
		ix[r][ci] = m;
		iy[r][ci] = n;
		return;
	}

	int cm = (ci + cj) >> 1;
	init(m, r, L(n), ci, cm);
	init(m, r, R(n), cm + 1, cj);

	min_st[m][n] = std::min(min_st[m][L(n)], min_st[m][R(n)]);
	max_st[m][n] = std::max(max_st[m][L(n)], max_st[m][R(n)]);
}

void init(const int & m, const int & ri, const int & rj)
{
	if(ri == rj)
	{
		init(m, ri, 0, 0, size - 1);
		return;
	}

	int l = L(m);
	int r = R(m);
	int rm = (ri + rj) >> 1;

	init(l, ri, rm);
	init(r, rm + 1, rj);

	for(int n = 0; n < size << 2; ++n)
	{
		min_st[m][n] = std::min(min_st[l][n], min_st[r][n]);
		max_st[m][n] = std::max(max_st[l][n], max_st[r][n]);
	}
}

pii rmq(const int & m, const int & n, const int & ci, const int & cj, const int & qi, const int & qj)
{
	if(cj < qi || ci > qj) return { INF, 0 };
	if(qi <= ci && cj <= qj) return { min_st[m][n], max_st[m][n] };

	int cm = (ci + cj) >> 1;

	pii ql = rmq(m, L(n), ci, cm, qi, qj);
	pii qr = rmq(m, R(n), cm + 1, cj, qi, qj);

	return { std::min(ql.first, qr.first), std::max(ql.second, qr.second) };
}

pii rmq(const int & m, const int & ri, const int & rj, const int & qri, const int & qrj, const int & qci, const int & qcj)
{
	if(rj < qri || ri > qrj) return { INF, 0 };
	if(qri <= ri && rj <= qrj) return rmq(m, 0, 0, size - 1, qci, qcj);

	int rm = (ri + rj) >> 1;

	pii ql = rmq(L(m), ri, rm, qri, qrj, qci, qcj);
	pii qr = rmq(R(m), rm + 1, rj, qri, qrj, qci, qcj);

	return { std::min(ql.first, qr.first), std::max(ql.second, qr.second) };
}

void update(const int & m, int n)
{
	do
	{
		n = P(n);
		min_st[m][n] = std::min(min_st[m][L(n)], min_st[m][R(n)]);
		max_st[m][n] = std::max(max_st[m][L(n)], max_st[m][R(n)]);
	}
	while(n);
}

void update(int m, const int & n, const int & val)
{
	min_st[m][n] = val;
	max_st[m][n] = val;
	update(m, n);

	do
	{
		m = P(m);
		min_st[m][n] = std::min(min_st[L(m)][n], min_st[R(m)][n]);
		max_st[m][n] = std::max(max_st[L(m)][n], max_st[R(m)][n]);
		update(m, n);
	}
	while(m);
}

int main()
{
	scanf("%d", &size);

	for(int i = 0; i < size; ++i)
	for(int j = 0; j < size; ++j)
		scanf("%d", &mat[i][j]);

	init(0, 0, size - 1);

	char str[2];
	int q, x1, y1, x2, y2, val;
	pii ans;

	scanf("%d", &q);
	while(q--)
	{
		scanf("%s", str);
		if(str[0] == 'q')
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1--; y1--; x2--; y2--;

			ans = rmq(0, 0, size - 1, x1, x2, y1, y2);
			printf("%d %d\n", ans.second, ans.first);
		}
		else
		{
			scanf("%d %d %d", &x1, &y1, &val);
			x1--; y1--;

			update(ix[x1][y1], iy[x1][y1], val);
		}
	}

	return 0;
}

