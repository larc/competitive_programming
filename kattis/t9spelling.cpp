#include <cstdio>
#include <string>

const std::string dic[] = {	"2"
							, "22"
							, "222"
							, "3"
							, "33"
							, "333"
							, "4"
							, "44"
							, "444"
							, "5"
							, "55"
							, "555"
							, "6"
							, "66"
							, "666"
							, "7"
							, "77"
							, "777"
							, "7777"
							, "8"
							, "88"
							, "888"
							, "9"
							, "99"
							, "999"
							, "9999"
							};

int main()
{
	std::string out;
	char line[1002];
	int n;

	scanf("%d", &n);
	fgets(line, sizeof(line), stdin);
	for(int c = 1; c <= n; ++c)
	{
		fgets(line, sizeof(line), stdin);

		out = " ";
		for(int i = 0; line[i] != '\n'; ++i)
		{
			const std::string & key = line[i] == ' ' ? "0" : dic[line[i] - 'a'];

			if(*std::rbegin(out) == key[0])
				out += ' ';

			out += key;
		}

		printf("Case #%d:%s\n", c, out.c_str());
	}

	return 0;
}

