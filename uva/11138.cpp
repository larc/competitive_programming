// 11138 - Nuts and Bolts

#include <cstdio>
#include <cstring>

#define MAX_BOLTS 500
#define MAX_NUTS 500

int nuts, bolts;
int fits[MAX_BOLTS][MAX_NUTS];

bool visited[MAX_BOLTS];
int match[MAX_NUTS];
int mcbm;

bool aug(const int & b)
{
	if(visited[b]) return 0;
	
	visited[b] = 1;
	for(int n = 0; n < nuts; n++)
		if(fits[b][n] && (match[n] == -1 || aug(match[n])))
		{
			match[n] = b;
			return 1;
		}

	return 0;
}

int main()
{
	int n_cases;

	scanf("%d", &n_cases);
	for(int c = 1; c <= n_cases; c++)
	{
		scanf("%d %d", &bolts, &nuts);
		for(int b = 0; b < bolts; b++)
		for(int n = 0; n < nuts; n++)
			scanf("%d", &fits[b][n]);

		mcbm = 0;
		memset(match, -1, sizeof(match));

		for(int b = 0; b < bolts; b++)
		{
			memset(visited, 0, sizeof(visited));
			if(aug(b)) mcbm++;
		}

		printf("Case %d: ", c);
		printf("a maximum of %d nuts and bolts ", mcbm);
		printf("can be fitted together\n");
	}

	return 0;
}

