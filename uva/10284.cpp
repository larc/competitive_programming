// 10284 - Chessboard in FEN

#include <cstdio>
#include <cstring>

#define piece(i) i >= 'a' ? i - 'a' : i - 'A'

char board[8][8];
void (*attack[26]) (const int & i, const int & j, const bool & black);

bool attack_square(const int & i, const int & j)
{
	if(i < 0 || i > 7) return 0;
	if(j < 0 || j > 7) return 0;

	if(board[i][j] > 0) return 0;

	board[i][j] = -1;
	return 1;
}


void pawn(const int & i, const int & j, const bool & black)
{
	attack_square(black ? i + 1 : i - 1, j - 1);
	attack_square(black ? i + 1 : i - 1, j + 1);
}

void knight(const int & i, const int & j, const bool & black)
{
	attack_square(i - 2, j - 1);
	attack_square(i - 2, j + 1);
	attack_square(i - 1, j - 2);
	attack_square(i - 1, j + 2);
	attack_square(i + 1, j - 2);
	attack_square(i + 1, j + 2);
	attack_square(i + 2, j - 1);
	attack_square(i + 2, j + 1);
}

void bishop(const int & i, const int & j, const bool & black)
{
	int a, b;

	a = i; b = j;
	while(attack_square(++a, ++b));

	a = i; b = j;
	while(attack_square(--a, --b));

	a = i; b = j;
	while(attack_square(++a, --b));

	a = i; b = j;
	while(attack_square(--a, ++b));
}

void rook(const int & i, const int & j, const bool & black)
{
	int a, b;

	a = i; b = j;
	while(attack_square(a, ++b));

	a = i; b = j;
	while(attack_square(a, --b));

	a = i; b = j;
	while(attack_square(++a, b));

	a = i; b = j;
	while(attack_square(--a, b));
}

void queen(const int & i, const int & j, const bool & black)
{
	bishop(i, j, black);
	rook(i, j, black);
}

void king(const int & i, const int & j, const bool & black)
{
	attack_square(i - 1, j - 1);
	attack_square(i - 1, j);
	attack_square(i - 1, j + 1);

	attack_square(i, j - 1);
	attack_square(i, j + 1);

	attack_square(i + 1, j - 1);
	attack_square(i + 1, j);
	attack_square(i + 1, j + 1);
}

int not_attacked()
{
	for(int i = 0; i < 8; ++i)
	for(int j = 0; j < 8; ++j)
		if(board[i][j] > 0)
			attack[piece(board[i][j])](i, j, board[i][j] >= 'a');

	int count = 0;
	for(int i = 0; i < 8; ++i)
	for(int j = 0; j < 8; ++j)
		if(!board[i][j]) count++;

	return count;
}

int main()
{
	attack['p' - 'a'] = pawn;
	attack['n' - 'a'] = knight;
	attack['b' - 'a'] = bishop;
	attack['r' - 'a'] = rook;
	attack['q' - 'a'] = queen;
	attack['k' - 'a'] = king;

	int i, j, k;

	char str[72];
	while(scanf("%s", str) != EOF)
	{
		memset(board, 0, sizeof(board));

		i = j = k = 0;
		while(str[k])
		{
			if(str[k] == '/') { i++; j = 0; }
			else if(str[k] >= '1' && str[k] <= '8') j += str[k] - '0';
			else board[i][j++] = str[k];

			k++;
		}

		printf("%d\n", not_attacked());
	}

	return 0;
}

