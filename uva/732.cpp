// 732 - Anagrams by Stack

#include <cstdio>
#include <cstring>
#include <stack>

#define N 128

char source[N];
char target[N];
char seq[N << 2];

std::stack<int> s;
void dfs_seq(const int n, const int i, const int j)
{
	if(!source[i] && !target[j])
	{
		seq[n - 1] = 0;
		printf("%s\n", seq);
		seq[n - 1] = ' ';
		return;
	}

	// in
	if(source[i])
	{
		seq[n] = 'i';
		s.push(source[i]);
		dfs_seq(n + 2, i + 1, j);
		s.pop();
	}

	// out
	if(!s.empty() && target[j] == s.top())
	{
		seq[n] = 'o';
		s.pop();
		dfs_seq(n + 2, i, j + 1);
		s.push(target[j]);
	}
}

int main()
{
	memset(seq, ' ', sizeof(seq));
	while(scanf("%s\n%s", source, target) != EOF)
	{
		printf("[\n");
		dfs_seq(0, 0, 0);
		printf("]\n");
	}

	return 0;
}

