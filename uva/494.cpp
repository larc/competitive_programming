#include <cstdio>

#define N 1024

bool is_letter(const char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main()
{
	char line[N];
	char * c;
	int count;

	while(fgets(line, N, stdin))
	{
		count = 0;
		c = line;
		while(*c != '\n')
		{
			if(is_letter(*c))
			{
				count++;
				while(is_letter(*++c));
			}
			c++;
		}
		printf("%d\n", count);
	}
	return 0;
}

