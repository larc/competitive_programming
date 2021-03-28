// Kenobi's Lightsabers

#include <cstdio>
#include <queue>

int main()
{
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif

	bool c = 1;
	int n, i;
	char str[5];
	std::deque<int> lightsabers[2];

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", str);
		if(str[0] == 'a')
		{
			scanf("%d", &i);
			if(lightsabers[!c].size() < lightsabers[c].size())
			{
				lightsabers[!c].push_back(lightsabers[c].front());
				lightsabers[c].pop_front();
			}

			lightsabers[c].push_back(i);
		}
		else if(str[0] == 't')
		{
			if(lightsabers[!c].size() == lightsabers[c].size())
			{
				lightsabers[c].push_front(lightsabers[!c].back());
				lightsabers[!c].pop_back();
			}
			lightsabers[c].pop_back();
		}
		else
		{
			c = !c;
			if(lightsabers[!c].size() > lightsabers[c].size())
			{
				lightsabers[c].push_front(lightsabers[!c].back());
				lightsabers[!c].pop_back();
			}
		}
	}

	printf("%lu\n", lightsabers[!c].size() + lightsabers[c].size());

	n = lightsabers[!c].size();
	while(n--)
	{
		printf("%d ", lightsabers[!c].front());
		lightsabers[!c].pop_front();
	}

	n = lightsabers[c].size();
	while(n--)
	{
		printf("%d", lightsabers[c].front());
		lightsabers[c].pop_front();

		if(n) printf(" ");
	}

	printf("\n");

	return 0;
}

