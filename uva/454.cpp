// 454 - Anagrams

#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

#define N 101

int freq[N][128];

bool is_anagram(const int & i, const int & j)
{
	for(int k = 0; k < 128; ++k)
		if(freq[i][k] != freq[j][k])
			return 0;

	return 1;
}

int main()
{
	int n, m;
	std::string phrase[N];

	scanf("%d\n\n", &n);
	while(n--)
	{
		m = 0;
		while(getline(std::cin, phrase[m]) && phrase[m].size()) m++;
		
		std::sort(phrase, phrase + m);
		memset(freq, 0, sizeof(freq));

		for(int i = 0; i < m; ++i)
		for(char & c: phrase[i])
			if(c != ' ') freq[i][c]++;
		
		for(int i = 0; i < m; ++i)
		for(int j = i + 1; j < m; ++j)
			if(is_anagram(i, j))
				std::cout << phrase[i] << " = " << phrase[j] << '\n';
		
		if(n) putchar('\n');
	}
	
	return 0;
}

