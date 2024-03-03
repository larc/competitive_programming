#include <algorithm>
#include <iostream>

using namespace std;

inline
int letter(const char c)
{
	if(c >= 'A' && c <= 'Z')
		return c - 'A';
	return c - 'a';
}

bool compare(const char a, const char b)
{
	if(letter(a) == letter(b))
		return a < b;
	return letter(a) < letter(b);
}

int main()
{
	int n;
	string str;

	cin >> n;
	while(n--)
	{
		cin >> str;
		sort(str.begin(), str.end(), compare);

		do
		{
			cout << str << endl;
		}
		while(next_permutation(str.begin(), str.end(), compare));
	}
	return 0;
}

