#include <cstdio>

#define next(i) (game[i]) % 3
#define prev(i) (game[i] + 1) % 3

int game[100];

bool log_possible(const int & n)
{
	bool p[3] = {};
	
	p[0] = 1;
	p[1] = 1;

	for(int i = 0; i < n; ++i)
	{
		if(!p[game[i] - 1]) return false;
		
		p[next(i)] = !p[next(i)];
		p[prev(i)] = !p[prev(i)];
	}

	return true;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d", game + i);
		
		if(log_possible(n)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

