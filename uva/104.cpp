// 104 - Arbitrage

#include <cstdio>
#include <cstring>

#define N 20

double G[N][N][N];
int P[N][N][N];

void print_path(const int & i, const int & j, const int & s)
{
	if(s > -1) print_path(i, P[i][j][s], s - 1);
	printf("%d ", j + 1);
}

int main()
{
	int n, a, length;
	double profit;

	while(scanf("%d", &n) != EOF)
	{
		memset(G, 0, sizeof(G));

		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(i != j && scanf("%lf", &G[i][j][0]));
			else G[i][j][0] = 1;

			P[i][j][0] = i;
		}
		
		for(int s = 1; s < n; s++) // path length 
		for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			profit = G[i][k][s - 1] * G[k][j][0];
			if(G[i][j][s] < profit)
			{
				G[i][j][s] = profit;
				P[i][j][s] = k;
			}
		}
		
		length = 0;
		for(int s = 1; !length && s < n; s++) 
		for(int i = 0; !length && i < n; i++)
			if(G[i][i][s] > 1.01)
			{
				length = s;
				a = i;
				break;
			}
	
		if(length)
		{	
			print_path(a, P[a][a][length], length - 1);
			printf("%d\n", a + 1);
		}
		else printf("no arbitrage sequence exists\n");
	}

	return 0;
}

