#include <cstdio>

int main()
{
	bool open = 0;
	char c;

	while((c = getchar()) != EOF)
	{
		if(c == '"')
		{
			if(open)
			{
				putchar('\'');
				putchar('\'');
			}
			else
			{
				putchar('`');
				putchar('`');
			}

			open = !open;
		}
		else putchar(c);
	}

	return 0;
}
