#include <cstdio>
#include <cstring>
#include <queue>

#define N 38
#define s 0
#define t N - 1

int G[N][N]; // adj matrix
int path[N]; // bfs tree
char M[N];

int augment(const int & v)
{
	if(path[v] >= 0 && v != path[v])
	{
		augment(path[v]);
		G[path[v]][v] -= 1;
		G[v][path[v]] += 1;
		M[v] = path[v] - 1 + 'A';
		return 1;
	}

	return 0;
}

int bfs()
{
	memset(path, -1, sizeof(path));
	std::queue<int> q;
	q.push(s);
	path[s] = 0;

	int u, v;
	while(!q.empty())
	{
		u = q.front();
		q.pop();

		if(u == t) break;

		for(v = 0; v < N; ++v)
		{
			if(G[u][v] > 0 && path[v] == -1)
			{
				path[v] = u;
				q.push(v);
			}
		}
	}

	return augment(t);
}

int main()
{
	int i, j, mf;

	char line[16];
	while(fgets(line, 16, stdin))
	{
		memset(G, 0, sizeof(G));
		memset(M, '_', sizeof(M));

		do
		{
			i = line[0] - 'A' + 1;
			G[s][i] = line[1] - '0';
			for(j = 3; line[j] != ';'; ++j)
				G[i][line[j] - '0' + 27] = 1;
		}
		while(fgets(line, 16, stdin) && line[0] != '\n');

		for(i = 27; i < t; ++i)
			G[i][t] = 1;

		while(bfs());

		mf = 0;
		for(i = 1; i < 27; ++i)
			mf += G[s][i];

		if(mf) printf("!\n");
		else
		{
			for(i = 27; i < t; ++i)
				putchar(M[i]);
			printf("\n");
		}
	}

	return 0;
}

