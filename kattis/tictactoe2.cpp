#include <cstdio>

int main()
{
	char str[3][4];
	int cx, co, wx, wo, n;

	scanf("%d", &n);
	do
	{
		cx = co = 0;
		for(int i = 0; i < 3; ++i)
		{
			scanf("%s", str[i]);
			for(int j = 0; str[i][j]; ++j)
			{
				if(str[i][j] == 'X') ++cx;
				if(str[i][j] == 'O') ++co;
			}
		}

		wx = wo = 0;
		for(int i = 0; i < 3; ++i)
		{
			if(str[i][i] == '.') continue;
			if(	(str[i][0] == str[i][1] && str[i][1] == str[i][2]) ||
				(str[0][i] == str[1][i] && str[1][i] == str[2][i])	)
				str[i][i] == 'X' ? ++wx : ++wo;
		}

		if(str[1][1] != '.')
		{
			if(	(str[0][0] == str[1][1] && str[1][1] == str[2][2]) ||
				(str[0][2] == str[1][1] && str[1][1] == str[2][0])	)
				str[1][1] == 'X' ? ++wx : ++wo;
		}

		(cx == co && wx < 1 && wo < 2) ||
		(cx == co + 1 && wx < 2 && wo < 1) ? printf("yes\n") : printf("no\n");
	}
	while(--n);

	return 0;
}

