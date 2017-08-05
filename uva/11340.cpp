#include <cstdio>
#include <cstring>

int main()
{
	unsigned char line[10001];
	int p[256];
	int n, k, m, v;
	unsigned char c;
	double pay;

	scanf("%d", &n);
	while(n--)
	{
		memset(p, 0, sizeof(p));

		scanf("%d", &k);
		while(k--)
		{
			scanf(" %c %d", &c, &v);
			p[c] = v;
		}
		
		pay = 0;
		scanf("%d", &m);
		c = getchar();
		while(m--)
		{
			fgets((char *) line, 10001, stdin);
			for(int i = 0; line[i] != '\0'; i++)
				pay += p[line[i]];
		}
		printf("%.2lf$\n", pay / 100);
	}

	return 0;
}

