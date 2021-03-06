// 101 - The Blocks Problem

#include <cstdio>
#include <vector>

#define N 25

int S[N], size[N];
int stack[N][N];

int find(const int & s, const int & x)
{
	for(int i = 0; i < size[s]; ++i)
		if(stack[s][i] == x) return i;
	
	return -1;
}

void reset(int i, const int & s)
{
	while(++i < size[s])
	{
		const int & j = stack[s][i];
		size[j] = 1;
		S[j] = j;
		stack[j][0] = j;
	}
}

int main()
{
	char cmd[5], opt[5];
	int n, a, b, sa, sb, ia, ib;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			size[i] = 1;
			stack[i][0] = i;
			S[i] = i;
		}
		
		while(scanf("%s", cmd), cmd[0] != 'q')
		{
			scanf("%d %s %d", &a, opt, &b);
			
			sa = S[a];
			sb = S[b];
			
			if(a == b || sa == sb) continue;

			ia = find(sa, a);
			ib = find(sb, b);

			if(opt[1] == 'n') // onto
			{
				reset(ib, sb);
				size[sb] = ib + 1;
			}

			if(cmd[0] == 'm')
			{
				reset(ia, sa);
				size[sa] = ia + 1;
			}
			

			for(int j = ia; j < size[sa]; ++j)
			{
				a = stack[sa][j];
				stack[sb][size[sb]++] = a;
				S[a] = sb;
			}

			size[sa] = ia;
		}
		
		for(int i = 0; i < n; ++i)
		{
			printf("%d:", i);
			for(int j = 0; j < size[i]; ++j)
				printf(" %d", stack[i][j]);

			putchar('\n');
		}
	}

	return 0;
}

