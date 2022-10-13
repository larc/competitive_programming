// 10685 - Nature

#include <iostream>
#include <string>
#include <map>

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
	map<string, int> creatures;

	int nc, nr;
	string xstr, ystr;

	while(cin >> nc >> nr)
	{
		if(!nc && !nr) break;

		for(int i = 0; i < nc; ++i)
		{
			cin >> xstr;
			creatures[xstr] = i;
		}

		uf.init(nc);
		while(nr--)
		{
			cin >> xstr >> ystr;
			uf.join(creatures[xstr], creatures[ystr]);
		}

		nr = 0;
		for(int i = 0; i < nc; ++i)
			if(nr < uf.S[i])
				nr = uf.S[i];

		cout << nr << '\n';
		creatures.clear();
	}

	return 0;
}

