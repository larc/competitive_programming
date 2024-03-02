#include <cstdio>
#include <map>
#include <string>

#define N 200001

using namespace std;

int size[N];
int friends[N];

int find_f(const int x)
{
	if(!size[x])
	{
		size[x] = 1;
		return friends[x] = x;
	}

	if(friends[x] == x) return x;
	return friends[x] = find_f(friends[x]);
}

int union_f(int & x, int & y)
{
	x = find_f(x);
	y = find_f(y);

	if(x != y)
	{
		size[x] += size[y];
		friends[y] = x;
	}

	return size[x];
}

int main()
{
	int c, n, x, y, id;
	map<string, int> ids;
	char name_a[21], name_b[21];

	scanf("%d", &c);
	while(c--)
	{
		ids.clear();
		id = 1;

		scanf("%d", &n);
		while(n--)
		{
			scanf("%s %s", name_a, name_b);
			if(!(x = ids[name_a]))
			{
				x = ids[name_a] = id++;
				size[x] = 0;
			}
			if(!(y = ids[name_b]))
			{
				y = ids[name_b] = id++;
				size[y] = 0;
			}

			printf("%d\n", union_f(x, y));
		}
	}

	return 0;
}

