// 132. Anagram String

#include <string>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	size_t T, c;
	string a, b;
	int letras[27];
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		memset(letras, 0, sizeof(letras));
		for(size_t i = 0; i < a.size(); ++i)
			letras[a[i] - 'a']++;

		for(size_t i = 0; i < b.size(); ++i)
			letras[b[i] - 'a']--;

		c = 0;
		for(size_t i = 0; i < 27; ++i)
			c += (size_t) abs((float)letras[i]);

		cout<<c<<endl;
	}
	return 0;
}
