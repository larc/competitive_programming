// 1103 - Ancient Messages

#include <cstdio>
#include <algorithm>

#define N 200

const char * hieroglyphs = "WAKJSD";
int image[N][N];
int h, w;

int hexa_to_int(const char c)
{
	if(c <= '9' && c >= '0') return c - '0';
	return  c - 'a' + 10;
}

void dfs_message(const int i, const int j, const int idx)
{
	if(i < 0 || i >= h) return;
	if(j < 0 || j >= w) return;
	if(image[i][j] >= 0) return;

	image[i][j] = idx;
	dfs_message(i - 1, j, idx);
	dfs_message(i + 1, j, idx);
	dfs_message(i, j - 1, idx);
	dfs_message(i, j + 1, idx);
}

int dfs_hieroglyphs(const int i, const int j)
{
	if(i < 0 || i >= h) return 0;
	if(j < 0 || j >= w) return 0;
	if(image[i][j]) return image[i][j];

	image[i][j] = -1;

	int a = dfs_hieroglyphs(i - 1, j);
	int b = dfs_hieroglyphs(i + 1, j);
	if(a < 0) a = b;
	else if(b >= 0) a = a == b ? a : 0;

	b = dfs_hieroglyphs(i, j - 1);
	if(a < 0) a = b;
	else if(b >= 0) a = a == b ? a : 0;

	b = dfs_hieroglyphs(i, j + 1);
	if(a < 0) a = b;
	else if(b >= 0) a = a == b ? a : 0;

	return a;
}

int main()
{
	char str[N * N + 1];
	int messages[N * N + 1];
	int c, n;

	int ncase = 1;
	while(scanf("%d %d", &h, &w), h && w)
	{
		for(int i = 0; i < h; ++i)
		{
			scanf("%s", str);
			for(int j = 0; j < w; ++j)
			{
				c = hexa_to_int(str[j]);
				image[i][(j << 2)] = 8 & c ? -1 : 0;
				image[i][(j << 2) + 1] = 4 & c ? -1 : 0;
				image[i][(j << 2) + 2] = 2 & c ? -1 : 0;
				image[i][(j << 2) + 3] = 1 & c ? -1 : 0;
			}
		}

		w <<= 2;

		n = 0;
		for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
			if(image[i][j] < 0)
			{
				dfs_message(i, j, ++n);
				messages[n] = 0;
			}

		for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
			if(!image[i][j])
				messages[dfs_hieroglyphs(i, j)]++;

		for(int i = 1; i <= n; ++i)
			str[i - 1] = hieroglyphs[messages[i]];

		str[n] = '\0';
		std::sort(str, str + n);

		printf("Case %d: %s\n", ncase++, str);
	}

	return 0;
}

