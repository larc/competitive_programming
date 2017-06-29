#include <cstdio>

#define N 30001

unsigned long long ways[N];

void change()
{
	int coins[] = {1, 5, 10, 25, 50};
	ways[0] = 1;
	for(int c = 0; c < 5; c++)
		for(int i = coins[c]; i < N; i++)
			ways[i] += ways[i - coins[c]];
}

int main()
{
	change();
	int c;
	while(scanf("%d", &c) != EOF)
	{
		if(ways[c] > 1)
			printf("There are %lld ways to produce %d cents change.\n", ways[c], c);
		else 
			printf("There is only 1 way to produce %d cents change.\n", c);
	}
	return 0;
}

