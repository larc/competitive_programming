#include <cstdio>

bool switched(char * c)
{
	while(*++c != '\0')
		if('a' <= *c && *c <= 'z')
			return 0;
	
	return 1;
}

int main()
{
	char word[101];
	scanf("%s", word);
	
	if(switched(word))
	{
		for(int i = 0; word[i] != '\0'; ++i)
			if('A' <= word[i] && word[i] <= 'Z')
				word[i] = word[i] - 'A' + 'a';
			else
				word[i] = word[i] - 'a' + 'A';
	}

	printf("%s\n", word);

	return 0;
}

