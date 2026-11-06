#include <cstdio>
#include <string>
#include <unordered_set>

int main()
{
	int n, l;
	char words[4001][13];
	std::unordered_set<std::string> dict;

	scanf("%d %d", &n, &l);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s", words[i]);
		dict.insert(words[i]);
	}

	int m = 0;
	int md = 0;
	int iw = 0;
	for(int i = 0; i < n; ++i)
	{
		int d = 0;
		char * w = words[i];
		do
		{
			const char org = *w;
			for(char c = 'a'; c <= 'z'; ++c)
			{
				*w = c;
				if(dict.contains(words[i]))
					++d;
			}
			*w = org;
		}
		while(*++w);

		d -= l;
		m += d;
		if(!d) ++iw;
		if(d > md) md = d;
	}

	printf("%d %d %d\n", m >> 1, md, iw);

	return 0;
}

