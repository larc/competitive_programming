#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
	char code[51];

	while(scanf("%s", code) && *code != '#')
	{
		if(std::next_permutation(code, code + strlen(code))) printf("%s\n", code);
		else printf("No Successor\n");
	}

	return 0;
}

