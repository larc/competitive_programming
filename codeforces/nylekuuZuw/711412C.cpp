#include <cstdio>

int main()
{
	const char * ans[2] = {"NO", "YES"};
	const char * h = "hello";
	char S[10001];

	scanf("%s", S);
	for(int i = 0; S[i]; ++i)
		if(S[i] == *h)
			if(!++h) break;

	printf("%s\n", ans[*h == 0]);

	return 0;
}

