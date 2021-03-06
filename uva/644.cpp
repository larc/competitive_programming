// 644 - Immediate Decodability

#include <cstdio>

#define N 11

int main()
{
	int n, m, n_sets, k;
	char str[N][N];

	n_sets = n = 0;
	while(scanf("%s", str[n++]) != EOF)
	{
		while(scanf("%s", str[n]) != EOF && str[n][0] != '9') n++;

		m = 0;
		for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(i != j)
			{
				k = 0;
				while(str[i][k] && str[j][k] && str[i][k] == str[j][k]) k++;
				m += str[i][k] == 0;
			}

		printf("Set %d is %simmediately decodable\n", ++n_sets, m ? "not " : "");
		n = 0;
	}
	
	return 0;
}

