// 10878 - Decode the tape

#include <cstdio>
#include <iostream>
#include <string>

int main()
{
	std::string line;
	char m;

	while(std::getline(std::cin, line))
	{
		m = 0;
		if(line[0] == '|')
		{
			for(auto & c: line)
			{
				if(c != '|' && c != '.')
				{
					m <<= 1;
					m += c == 'o';
				}
			}
			putchar(m);
		}
	}

	return 0;
}

