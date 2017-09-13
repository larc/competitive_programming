#include <cstdio>
#include <cstring>

#define N 38

int G[N][N];
int size[N];

int main()
{
	int i, j;

	char line[16];
	while(fgets(line, 16, stdin))
	{
		memset(size, 0, sizeof(N));
		
		do
		{
			i = line[0] - 'A' + 1;
			for(j = 3; line[j] != ';'; j++)
				G[i][size[i]++] = j - '0' + 27;
		}
		while(fgets(line, 16, stdin) && line[0] != '\n');

		printf("!\n");
	}

	return 0;
}
