// 11503 - Virtual Friends

#include <cstdio>
#include <string>
#include <unordered_map>

#define N 200001

using namespace std;

int num[N];
int friends[N];

int find_f(const int x)
{
	return x == friends[x] ? x : friends[x] = find_f(friends[x]);
}

int union_f(int & x, int & y)
{
	x = find_f(x);
	y = find_f(y);

	if(x != y)
	{
		num[x] += num[y];
		friends[y] = x;
	}

	return num[x];
}

int main()
{
	int c, n, id;
	unordered_map<string, int> ids;
	char name_a[21], name_b[21];

	scanf("%d", &c);
	while(c--)
	{
		ids.clear();
		id = 0;

		scanf("%d", &n);
		while(n--)
		{
			scanf("%s %s", name_a, name_b);
			int & a = ids[name_a];
			int & b = ids[name_b];
			if(!a) { a = ++id; num[a] = 1; friends[a] = a; }
			if(!b) { b = ++id; num[b] = 1; friends[b] = b; }

			printf("%d\n", union_f(a, b));
		}
	}

	return 0;
}

