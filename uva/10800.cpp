// 10800 - Not That Kind of Graph

#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
	char plot[108][54], str[54];
	int n, nx, x, maxy, miny, y;

	scanf("%d", &n);
	for(int c = 1; c <= n; ++c)
	{
		memset(plot, ' ', sizeof(plot));
		scanf("%s", str);

		maxy = 0; miny = 107; y = 54;
		for(nx = 0; str[nx]; ++nx)
		{
			if(str[nx] == 'R')
			{
				maxy = std::max(maxy, y);
				miny = std::min(miny, y);
				plot[y][nx + 2] = '/';
				y++;
			}
			else if(str[nx] == 'F')
			{
				y--;
				plot[y][nx + 2] = '\\';
				maxy = std::max(maxy, y);
				miny = std::min(miny, y);
			}
			else
			{
				plot[y][nx + 2] = '_';
				maxy = std::max(maxy, y);
				miny = std::min(miny, y);
			}
		}

		nx += 3;
		
		memset(str, '-', sizeof(str));
		str[0] = '+';
		str[nx] = 0;
		
		printf("Case #%d:\n", c);
		for(y = maxy; y >= miny; y--)
		{
			plot[y][0] = '|';
			for(x = nx; plot[y][x] == ' '; x--);
			plot[y][x + 1] = 0;
			printf("%s\n", plot[y]);
		}

		printf("%s\n\n", str);
	}

	return 0;
}

