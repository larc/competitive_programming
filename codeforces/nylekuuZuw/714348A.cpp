#include <cstdio>

bool balanced(char * str)
{
	int j = -1;
	for(int i = 0; str[i]; ++i)
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			str[++j] = str[i];
		else if(j < 0) return false;
		else if(str[i] == ')' && str[j] != '(') return false;
		else if(str[i] == '}' && str[j] != '{') return false;
		else if(str[i] == ']' && str[j] != '[') return false;
		else --j;

	return j < 0;
}

int main()
{
	int n;
	char str[1001];

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", str);
		printf("%s\n", balanced(str) ? "YES" : "NO");
	}

	return 0;
}

