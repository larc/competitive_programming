// 11550 - Demanding Dilemma

#include <cstdio>
#include <string>

bool is_simple_graph(std::string * mat, const int & m)
{
	int nv;
	for(int i = 0; i < m; ++i)
	{
		nv = 0;
		for(char & c: mat[i])
			nv += c == '1';

		if(nv != 2) return false;

		for(int j = 0; j < m; ++j)
			if(i != j && mat[i] == mat[j])
				return false;
	}
	return true;
}

int main()
{
	int n_cases, n, m, v;
	std::string mat[28];

	scanf("%d", &n_cases);
	do
	{
		scanf("%d %d", &n, &m);
		for(int j = 0; j < m; ++j)
			mat[j] = "";

		for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", &v);
			mat[j] += '0' + v;
		}

		printf("%s\n", is_simple_graph(mat, m) ? "Yes" : "No");
	}
	while(--n_cases);

	return 0;
}

