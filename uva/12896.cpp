// 12896 - Mobile SMS

#include <cstdio>

char T[100] = {};

void init()
{
	T[1] = ' ';
	T[11] = '.';
	T[12] = ',';
	T[13] = '?';
	T[14] = '\"';
	T[21] = 'a';
	T[22] = 'b';
	T[23] = 'c';
	T[31] = 'd';
	T[32] = 'e';
	T[33] = 'f';
	T[41] = 'g';
	T[42] = 'h';
	T[43] = 'i';
	T[51] = 'j';
	T[52] = 'k';
	T[53] = 'l';
	T[61] = 'm';
	T[62] = 'n';
	T[63] = 'o';
	T[71] = 'p';
	T[72] = 'q';
	T[73] = 'r';
	T[74] = 's';
	T[81] = 't';
	T[82] = 'u';
	T[83] = 'v';
	T[91] = 'w';
	T[92] = 'x';
	T[93] = 'y';
	T[94] = 'z';
}

int main()
{
	init();

	int n_cases, n, p;
	int keys[100];
	char message[101];

	scanf("%d", &n_cases);
	do
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", keys + i);

		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &p);
			message[i] = T[10 * keys[i] + p];
		}

		message[n] = 0;
		printf("%s\n", message);
	}
	while(--n_cases);

	return 0;
}

