#include <cstdio>
#include <string>

				//	ABCDEFGHIJKLMNOPQRSTUVWXYZ
char soundex[27] = "01230120022455012623010202";

int main()
{
	char word[21];
	std::string code;

	while(scanf("%s", word) != EOF)
	{
		for(char & c: word)
			c = soundex[c - 'A'];

		int i = 0;
		while(word[i] && word[i] == '0') ++i;

		code = word[i] ? word[i++] : '\0';
		for(; word[i]; ++i)
		{
			if(word[i] != '0' && word[i] != word[i - 1])
				code += word[i];
		}

		printf("%s\n", code.c_str());
	}

	return 0;
}

