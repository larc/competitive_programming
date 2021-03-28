// 12705 - Breaking Board

#include <cstdio>
#include <map>
#include <queue>

using namespace std;

int cost[36] = {	2,
					3, 3,
					4, 4, 4,
					5, 5, 5, 5,
					6, 6, 6, 6, 6,
					7, 7, 7, 7, 7, 7,
					8, 8, 8, 8, 8,
					9, 9, 9, 9,
					10, 10, 10,
					11, 11,
					12 };

int main()
{
	int n, min_cost;
	char str[128];
	char * c;

	scanf("%d", &n);
	fgets(str, 128, stdin);
	while(n--)
	{
		fgets(str, 128, stdin);
		map<char, int> freq;
		priority_queue<pair<int, char> > q;

		c = str;
		while(*c != '\n')
		{
			if(*c != ' ') freq[*c]++;
			c++;
		}

		for(auto & p: freq)
			q.push({p.second, p.first});

		min_cost = 0;
		for(int i = 0; !q.empty(); ++i)
		{
			min_cost += q.top().first * cost[i];
			q.pop();
		}

		printf("%d\n", min_cost);
	}

	return 0;
}

