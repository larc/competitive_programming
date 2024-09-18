// 1569 - Snakes and Ladders

#include <cstdio>
#include <cstring>


int main()
{
	int board[101];
	int players[1000000];
	int n, a, b, c, u, v;
	bool play;

	scanf("%d", &n);
	while(n--)
	{
		memset(board, 0, sizeof(board));

		scanf("%d %d %d", &a, &b, &c);
		while(b--)
		{
			scanf("%d %d", &u, &v);
			board[u] = v;
		}

		for(int i = 0; i < a; ++i)
			players[i] = 1;

		u = 0;
		play = true;
		while(c--)
		{
			scanf("%d", &b);

			if(!play) continue;

			players[u] += b;
			if(players[u] >= 100)
				players[u] = 100;
			if(board[players[u]])
				players[u] = board[players[u]];

			if(players[u] >= 100)
				play = false;

			u = (u + 1) % a;
		}

		for(int i = 0; i < a; ++i)
			printf("Position of player %d is %d.\n", i + 1, players[i]);
	}

	return 0;
}

