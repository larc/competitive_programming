#include <string>
#include <cstring>
#include <iostream>

using namespace std;

char reverse[256];
void init_reverse()
{
	memset(reverse, 0, sizeof(reverse));

	reverse['A'] = 'A';
	reverse['E'] = '3';
	reverse['H'] = 'H';
	reverse['I'] = 'I';
	reverse['J'] = 'L';
	reverse['L'] = 'J';
	reverse['M'] = 'M';
	reverse['O'] = 'O';
	reverse['S'] = '2';
	reverse['T'] = 'T';
	reverse['U'] = 'U';
	reverse['V'] = 'V';
	reverse['W'] = 'W';
	reverse['X'] = 'X';
	reverse['Y'] = 'Y';
	reverse['Z'] = '5';
	reverse['1'] = '1';
	reverse['2'] = 'S';
	reverse['3'] = 'E';
	reverse['5'] = 'Z';
	reverse['8'] = '8';
}

bool is_palindrome(const string & str)
{
	for(int j = str.size() - 1,i = 0; i < j; i++, j--)
		if(str[i] != str[j]) return false;
	return true;
}

bool is_mirror(const string & str)
{
	for(int j = str.size() - 1,i = 0; i <= j; i++, j--)
		if(str[j] != reverse[str[i]]) return false;
	return true;
}

int main()
{
	init_reverse();

	string str;
	bool p, m;
	while(cin >> str)
	{
		p = is_palindrome(str);
		m = is_mirror(str);
		cout << str;
		if(!p && !m) cout << " -- is not a palindrome." << endl;
		else if(p && !m) cout << " -- is a regular palindrome." << endl;
		else if(!p && m) cout << " -- is a mirrored string." << endl;
		else cout << " -- is a mirrored palindrome." << endl;
		cout << endl;
	}
	return 0;
}

