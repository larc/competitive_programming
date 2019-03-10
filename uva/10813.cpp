// 10813 - Traditional BINGO

#include <cstdio>
#include <cstring>

#define N 76

int main()
{
	int game[N], row[5], col[5], diag[2];
	int n, b, r, c, num;

	scanf("%d", &n);
	while(n--)
	{
		memset(game, -1, sizeof(game));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		diag[0] = diag[1] = 0;

		for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(i != 2 || j != 2)
			{
				scanf("%d", &num);
				game[num] = i;
			}

		
		b = 0;
		for(int i = 1; i < N; i++)
		{
			scanf("%d", &num);

			if(game[num] < 0) continue;
			if(b) continue;

			r = game[num];
			c = (num - 1) / 15;
			
			if(++row[r] == 5 - (r == 2)) b = i;
			if(++col[c] == 5 - (c == 2)) b = i;
			if(c == r && ++diag[0] == 4) b = i;
			if(c + r == 4 && ++diag[1] == 4) b = i;
		}
		
		printf("BINGO after %d numbers announced\n", b);
	}

	return 0;
}

