// 11831 - Sticker Collector Robot

#include <cstdio>
#include <cstring>

#define N 102

char arena[N][N];
int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1};

bool forward(int & i, int & j, const int & d)
{
	if(!arena[i + x[d]][j + y[d]])
		return 0;
	if(arena[i + x[d]][j + y[d]] == '#')
		return 0;
	
	i += x[d];
	j += y[d];
	
	if(arena[i][j] == '*')
	{
		arena[i][j] = '.';
		return 1;
	}

	return 0;
}

int main()
{
	char str[50001];
	int n, m, d, s, a, b;
	
	while(scanf("%d %d %d", &n, &m, &s) && n && m && s)
	{
		memset(arena, 0, sizeof(arena));

		d = -1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", arena[i] + 1);
			for(int j = 1; d < 0 && j <= m; j++)
			{
				switch(arena[i][j])
				{
					case 'N': d = 0; break;
					case 'L': d = 1; break;
					case 'S': d = 2; break;
					case 'O': d = 3; break;
				};
				if(d >= 0) { a = i; b = j; }
			}
		}

		scanf("%s", str);

		s = 0;
		for(int i = 0; str[i]; i++)
			if(str[i] == 'F') s += forward(a, b, d);
			else d = str[i] == 'D' ? (d + 1) % 4 : (d + 3) % 4;

		printf("%d\n", s);
	}

	return 0;
}

