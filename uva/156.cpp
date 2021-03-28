#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

inline
int index(const char & c)
{
	if(c >= 'A' && c <= 'Z')
		return c - 'A';

	return c - 'a';
}

int main()
{
	int compare[1000][27] = {0};
	string words[1000];
	string word;

	int n = 0;
	while(cin >> word && word[0] != '#')
	{
		for(char & c: word)
			compare[n][index(c)]++;

		words[n++] = word;
	}

	int c, na = 0;
	for(int i = 0; i < n; ++i)
	{
		if(!compare[i][26])
		for(int j = i + 1; j < n; ++j)
		{
			c = 0;
			for(int k = 0; k < 26; ++k)
				c += compare[i][k] == compare[j][k];

			if(c == 26)
			{
				compare[i][26] = 1;
				compare[j][26] = 1;
			}
		}

		if(!compare[i][26]) words[na++] = words[i];
	}

	sort(words, words + na);

	for(int i = 0; i < na; ++i)
		cout << words[i] << endl;

	return 0;
}

