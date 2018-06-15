// 1062 - Containers

#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	bool push;
	char str[1001];
	int k, n_cases = 1;
	vector<stack<char> > vs;

	while(scanf("%s", str), str[0] != 'e')
	{
		k = 0;
		while(str[k])
		{
			push = 0;
			for(auto & s: vs)
			{
				if(s.top() >= str[k])
				{
					push = 1;
					s.push(str[k]);
					break;
				}
			}

			if(!push)
			{
				vs.push_back(stack<char>());
				vs.back().push(str[k]);
			}

			k++;
		}

		printf("Case %d: %lu\n", n_cases++, vs.size());
		vs.clear();
	}

	return 0;
}

