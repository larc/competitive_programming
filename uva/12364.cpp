// 12364 - In Braille

#include <iostream>
#include <string>

#define MAX_N 300

using namespace std;

char str_braile[3][MAX_N];

string braile[10] = {	".***..",	// 0
						"*.....",	// 1
						"*.*...",	// 2
						"**....",	// 3
						"**.*..",	// 4
						"*..*..",	// 5
						"***...",	// 6
						"****..",	// 7
						"*.**..",	// 8
						".**..."	// 9
						};

void to_braile(const string & str)
{
	for(unsigned int i = 0; i < str.size(); ++i)
	{
		const string & num = braile[str[i] - '0'];

		const int k = 3 * i;
		for(int j = 0; j < 3; ++j)
		{
			str_braile[j][k    ] = num[2 * j];
			str_braile[j][k + 1] = num[2 * j + 1];
			str_braile[j][k + 2] = ' ';
		}
	}

	int n = str.size() * 3;
	for(int j = 0; j < 3; ++j)
	{
		str_braile[j][n - 1] = '\0';
		cout << str_braile[j] << endl;
	}
}

int find(const string & str)
{
	for(int i = 0; i < 10; ++i)
		if(str == braile[i])
			return i;

	return -1;
}

void to_num(string & str, const int s)
{
	str = "";
	string num;

	for(int i = 0; i < s; ++i)
	{
		num = "";

		const int k = 3 * i;
		for(int j = 0; j < 3; ++j)
		{
			num += str_braile[j][k];
			num += str_braile[j][k + 1];
		}

		str += find(num) + '0';
	}

	cout << str << endl;
}

int main()
{
	int d;
	char c;
	string str;

	while(cin >> d && d)
	{
		cin >> c;
		if(c == 'S')
		{
			cin >> str;
			to_braile(str);
		}
		else
		{
			cin.getline(str_braile[0], MAX_N);
			for(int j = 0; j < 3; ++j)
				cin.getline(str_braile[j], MAX_N);
			to_num(str, d);
		}
	}

	return 0;
}

