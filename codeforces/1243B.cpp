#include <cstdio>

#define N 10001

int diff(const char * s, const char * t, int i)
{
	for(; s[i]; ++i)
		if(s[i] != t[i])
			break;
	
	return i;
}

int main()
{
	char s[N], t[N];
	int k, n, a, b;

	scanf("%d", &k);
	while(k--)
	{
		scanf("%d", &n);
		scanf("%s", s);
		scanf("%s", t);
		
		a = diff(s, t, 0);
		b = diff(s, t, a + 1);

		if(diff(s, t, b + 1) < n)
			printf("NO\n");
		else if(s[a] == s[b] && t[a] == t[b])
			printf("YES\n");
		else printf("NO\n");
				
	}
	return 0;
}

