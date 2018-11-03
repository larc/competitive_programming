// 13169 - Balls and Needles

#include <cstdio>
#include <cstring>
#include <map>

#define K 50000
#define N 100001

typedef std::pair<int, int> pii;
typedef std::pair<pii, int> piii;

struct edge_t
{
	int u, v;
};

struct union_find
{
	int comp[N];
	
	void init(const int & n)
	{
		for(int i = 1; i <= n; i++)
			comp[i] = i;
	}

	int find(const int & x)
	{
		if(x == comp[x]) return x;
		return comp[x] = find(comp[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y) return 0;

		comp[y] = x;
		return 1;
	}
};


int main()
{
	std::map<piii, int> mxyz;
	std::map<pii, int> mxy;
	std::map<pii, bool> XY;

	union_find ufxy, ufxyz;
	edge_t exy[K], exyz[K];

	int k, nxy, nxyz, x, y, z;

	while(scanf("%d", &k) != EOF)
	{
		nxy = nxyz = 0;
		for(int i = 0; i < k; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			exy[i].u = mxy[{x, y}] ? mxy[{x, y}] : mxy[{x, y}] = ++nxy;
			exyz[i].u = mxyz[{{x, y}, z}] ? mxyz[{{x, y}, z}] : mxyz[{{x, y}, z}] = ++nxyz;
			
			scanf("%d %d %d", &x, &y, &z);
			exy[i].v = mxy[{x, y}] ? mxy[{x, y}] : mxy[{x, y}] = ++nxy;
			exyz[i].v = mxyz[{{x, y}, z}] ? mxyz[{{x, y}, z}] : mxyz[{{x, y}, z}] = ++nxyz;
			
			if(XY[{exy[i].u, exy[i].v}]) exy[i].u = exy[i].v = 0;
			else XY[{exy[i].u, exy[i].v}] = XY[{exy[i].v, exy[i].u}] = 1;
		}
		
		ufxyz.init(nxyz);
		ufxy.init(nxy);

		x = y = 0;
		for(int i = 0; i < k; i++)
		{
			if(!ufxyz.join(exyz[i].u, exyz[i].v)) x++;
			if(exy[i].u != exy[i].v && !ufxy.join(exy[i].u, exy[i].v)) y++;
		}

		if(x) printf("True closed chains\n");
		else printf("No true closed chains\n");

		if(y) printf("Floor closed chains\n");
		else printf("No floor closed chains\n");

		mxyz.clear();
		mxy.clear();
		XY.clear();
	}

	return 0;
}

