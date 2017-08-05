#include <cstdio>
#include <cstring>

int main()
{
	int round, guess;
	char letter[27], c, n;
	while(scanf("%d", &round) && round != -1)
	{
		n = 0;
		memset(letter, 0, sizeof(letter));

		c = getchar();
		while((c = getchar()) != '\n')
			if(!letter[c -= 'a'])
			{
				n++;
				letter[c] = 1;
			}
		
		guess = 7;
		while((c = getchar()) != '\n')
			if(guess && n)
			{
				if(letter[c -= 'a'] == 1)
				{
					letter[c] = -1;
					n--;
				}
				else if(!letter[c])
				{
					letter[c] = -1;
					guess--;
				}
			}
		
		printf("Round %d\n", round);
		if(!n) printf("You win.\n");
		else if(!guess) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	return 0;
}

