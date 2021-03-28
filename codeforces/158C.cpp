#include <cstdio>

#define N 201

int main()
{
	char pwd[N * 50], cmd[4], path[N];

	int n, idx, i;
	scanf("%d", &n);

	pwd[idx = 0] = 0;
	while(n--)
	{
		scanf("%s", cmd);
		if(cmd[0] == 'c') // cd
		{
			scanf("%s", path);

			i = 0;
			if(path[i] == '/') { idx = 0; i++; }
			while(path[i])
			{
				if(path[i] == '.' && path[i + 1] == '.')
				{
					i += 2;
					idx -= 2;
					while(idx >= 0 && pwd[idx] != '/') idx--;
					idx++;
				}
				else
				{
					while(path[i] && path[i] != '/')
						pwd[idx++] = path[i++];

					pwd[idx++] = '/';
				}

				if(path[i] == '/') i++;
				pwd[idx] = 0;
			}
		}
		else printf("/%s\n", pwd);
	}

	return 0;
}

