// 139. RLE Secret

#include <string>
#include <iostream>

using namespace std;

int main()
{
	size_t T, s;
	string str;
	char c;

	cin>>T;
	while(T--)
	{
		cin>>str;
		s = 1;
		c = str[0];
		for(size_t i = 1; i < str.size(); i++)
			if(str[i] != c)
			{
				cout<<c<<s;
				s = 1;
				c = str[i];
			}
			else s++;
		cout<<c<<s<<endl;
	}
	return 0;
}
