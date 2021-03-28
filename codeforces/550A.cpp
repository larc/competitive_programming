#include <cstdio>
#include <vector>

#define N 100001

int main()
{
	std::vector<unsigned> ab, ba;
	ab.reserve(N);
	ba.reserve(N);

	char str[N];
	scanf("%s", str);

	for(unsigned i = 1; str[i]; ++i)
	{
		if(str[i - 1] == 'A' && str[i] == 'B') ab.push_back(i);
		if(str[i - 1] == 'B' && str[i] == 'A') ba.push_back(i);
	}

	if(ab.size() && ba.size() && ((ab.front() < ba.back() && ab.front() != ba.back() - 1) ||
									(ba.front() < ab.back() && ba.front() != ab.back() - 1)))
		printf("YES\n");
	else printf("NO\n");

	return 0;
}

