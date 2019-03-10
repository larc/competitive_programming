// 161 - Traffic Lights

#include <cstdio>

int main()
{
	int C[101], n, g, t;

	while(scanf("%d", C) && C[0])
	{
		n = 1; t = C[0] << 1;
		while(scanf("%d", C + n) && C[n])
		{
			if((C[n] << 1) < t) t = C[n] << 1;
			n++;
		}
		
		for(; t <= 18000; t++)
		{
			g = 0;
			for(int i = 0; i < n; i++)
				g += t % (C[i] << 1) < C[i] - 5;

			if(g == n) break;
		}
		
		if(g == n) printf("%02d:%02d:%02d\n", t / 3600, t % 3600 / 60, t % 60);
		else printf("Signals fail to synchronise in 5 hours\n");
	}
	
	scanf("%d %d", C, C + 1);

	return 0;
}

