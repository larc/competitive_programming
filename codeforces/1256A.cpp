#include <cstdio>

#define N 1000000

using namespace std;

int main()
{
	int q, a, b, n, S;

	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d %d %d", &a, &b, &n, &S);
		
		if(S / n <= a) S -= (S / n) * n;
		else S -= a * n;
		
		if(S <= b) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

