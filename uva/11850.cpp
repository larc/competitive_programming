#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int x, vec[1500], n;
	bool b;	
	while(scanf("%d", &n) != EOF && n)
	{
		for(x = 0; x < n; x++)
			scanf("%d", &vec[x]);
		vec[n++] = 0;
		sort(vec, vec + n);
		vec[n] = 1422 + 1422 - vec[n - 1];

		b = 1;
		for(x = 0; x < n; x++)
			if(vec[x + 1] - vec[x] > 200)
			{
				b = 0;
				break;
			}

		if(b) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}

	return 0;
}
