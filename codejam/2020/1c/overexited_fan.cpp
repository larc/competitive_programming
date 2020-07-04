#include <cstdio>
#include <cmath>

int main()
{
	char M[1001];
	int T, X, Y, D, dist, time;

	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d %s", &X, &Y, M);

		time = 0;
		dist = 1001;

		do
		{
			D = std::abs(X) + std::abs(Y);
			if(D <= time && time < dist)
				dist = time;
			
			switch(M[time])
			{
				case 'E': X++; break;
				case 'N': Y++; break;
				case 'W': X--; break;
				case 'S': Y--; break;
			}
		}
		while(M[time++]);

		if(dist < 1001) printf("Case #%d: %d\n", t, dist);
		else printf("Case #%d: IMPOSSIBLE\n", t);
	}

	return 0;
}

