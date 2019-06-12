// 7431 - Identifying Map Tiles

#include <cstdio>

int main()
{
	int x, y, i;
	char str[32];

	while(scanf("%s", str) != EOF)
	{
		x = y = 0;
		for(i = 0; str[i]; i++)
		{
			x <<= 1;
			y <<= 1;
			if(str[i] == '1' || str[i] == '3') x++;
			if(str[i] == '2' || str[i] == '3') y++;
		}

		printf("%d %d %d\n", i, x, y);
	}

	return 0;
}
