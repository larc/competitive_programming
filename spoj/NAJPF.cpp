#include <cstdio>

#define N 1000001

char P[N], T[N];
unsigned b[N];
unsigned idx[N];

void init_kmp()
{
	int i = 0, j = b[0] = -1;
	while(P[i])
	{
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

int kmp()
{
	int i = 0, j = 0, s = 0;
	while(T[i])
	{
		while(j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		
		if(!P[j]) // match
		{
			idx[s++] = i - j + 1;
			j = b[j];
		}
	}

	return s;
}

int main()
{
	int n, s;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s %s", T, P);

		init_kmp();
		if(s = kmp())
		{
			printf("%d\n%d", s, idx[0]);
			for(int i = 1; i < s; i++)
				printf(" %d", idx[i]);
			putchar('\n');
		}
		else printf("Not Found\n");

		if(n) putchar('\n');
	}

	return 0;
}

