// 10298 - Power Strings

#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool is_pow;
	int n, m, d;
	int div[2001];

	string str;
	while(cin >> str, str[0] != '.')
	{
		n = 0;
		for(d = 1; d * d < str.size(); d++)
			if(!(str.size() % d))
			{
				div[n++] = d;
				div[n++] = str.size() / d;
			}

		if(d * d ==  str.size()) div[n++] = d;
		
		m = 1;
		for(int i = 0; i < n; i++)
		{
			d = div[i];
			is_pow = 1;
			for(int j = d; j < str.size() && is_pow; j += d)
			for(int k = 0; k < d; k++)
				if(str[k] != str[j + k])
				{
					is_pow = 0;
					break;
				}

			if(is_pow && str.size() / d > m) m = str.size() / d;
		}

		printf("%d\n", m);
	}

	return 0;
}

