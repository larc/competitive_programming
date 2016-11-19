#include <cstdio>
#include <cstring>

int C[10];
bool V[10];
int P[27];
int e[27];
int A[27][10];

bool path_aumenting(int p)
{
	int i;
	while(e[p] < 10)
	{
		i = e[p]++;
		if(!V[i] && A[p][i] == 1)
			if(!C[i])
			{
				A[C[i] - 1][i] = 1;
				C[i] = p + 1;
				A[p][i] = 2;
				return true;
			}
			else
			{
				V[i] = 1;
				if(path_aumenting(C[i] - 1))
				{
					A[C[i] - 1][i] = 1;
					C[i] = p + 1;
					A[p][i] = 2;
					return true;
				}
				V[i] = 0;
			}	
	}
	return false;
}

int main()
{
	char p[2], c[1024];
	int i, j;

//	while(scanf("%c", &p[0]) != EOF && p[0] != '\n')
	while(scanf("%s %s", p, c) != EOF)
	{
//		scanf("%c %s", &p[1], c);

		memset(C, 0, sizeof(C));
		memset(P, 0, sizeof(P));
		memset(A, 0, sizeof(A));

		i = 0;
		P[p[0] - 'A'] = p[1] - '0';
		while(c[i] != ';') A[p[0] - 'A'][c[i++] - '0'] = 1;

		while(scanf("%c", &p[0]) != EOF && scanf("%c", &p[0]) != EOF && p[0] != '\n')
		{
			scanf("%c %s", &p[1], c);
	
			i = 0;
			P[p[0] - 'A'] = p[1] - '0';
			while(c[i] != ';') A[p[0] - 'A'][c[i++] - '0'] = 1;
		}
		
		//fill bi-partite graph
		for(i = 0; i < 27; i++)
			for(j = 0; j < 10; j++)
				if(P[i] && A[i][j] == 1 && !C[j])
				{
					C[j] = i + 1;
					P[i]--;
					A[i][j] = 2;
				}

		j = 0;
		for(i = 0; i < 27; i++)
		{
			memset(e, 0, sizeof(e));
			memset(V, 0, sizeof(V));
			while(P[i] && path_aumenting(i)) P[i]--;
			if(P[i])
			{
				j = 1;
				break;
			}
		}

		if(j) printf("!\n");
		else
		{
			for(i = 0; i < 10; i++)
				if(C[i]) printf("%c", (char) C[i] - 1 + 'A');
				else printf("_");
			printf("\n");
		}
	}

	return 0;
}
