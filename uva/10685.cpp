// 10685 - Nature

#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

struct union_find
{
	int P[5000];
	int S[5000];

	void init(const int & n)
	{
		for(int i = 0; i < n; ++i)
		{
			P[i] = i;
			S[i] = 1;
		}
	}

	int find(const int & x)
	{
		return x == P[x] ? x : P[x] = find(P[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y) return false;

		P[y] = x;
		S[x] += S[y];

		return true;
	}
};

int main()
{
	union_find uf;
	unordered_map<string, int> creatures;

	int nc, nr;
	char xstr[32], ystr[32];

	while(scanf("%d %d", &nc, &nr) && nc)
	{
		for(int i = 0; i < nc; ++i)
		{
			scanf("%s", xstr);
			creatures[xstr] = i;
		}

		uf.init(nc);
		while(nr--)
		{
			scanf("%s %s", xstr, ystr);
			uf.join(creatures[xstr], creatures[ystr]);
		}

		nr = 0;
		for(int i = 0; i < nc; ++i)
			if(nr < uf.S[i])
				nr = uf.S[i];

		printf("%d\n", nr);
		creatures.clear();
	}

	return 0;
}

