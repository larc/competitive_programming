#include <cstdio>

int main()
{
	int n, a, d;
	char str[100'001];

	scanf("%d", &n);
	scanf("%s", str);

	a = d = 0;
	for(int i = 0; i < n; ++i)
		if(str[i] == 'A') a++;
		else d++;

	if(a == d) printf("Friendship\n");
	else if(a > d) printf("Anton\n");
	else printf("Danik\n");

	return 0;
}

