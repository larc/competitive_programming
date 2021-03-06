#include <cstdio>
#include <string>

int main()
{
	int T, n, p;
	char S[101];
	std::string y;

	scanf("%d", &T);
	for(int x = 1; x <= T; ++x)
	{
		scanf("%s", S);
		
		y = "";
		p = 0;
		for(int i = 0; S[i]; ++i)
		{
			n = S[i] - '0';
			
			while(p > n)
			{
				y += ')';
				p--;
			}
			
			while(p < n)
			{
				y += '(';
				p++;
			}
				
			y += S[i];
		}

		while(p)
		{
			y += ')';
			p--;
		}

		printf("Case #%d: %s\n", x, y.c_str());
	}

	return 0;
}

