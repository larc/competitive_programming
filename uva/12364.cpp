// 12364 - In Braille

#include <iostream>
#include <string>

using namespace std;

char str_braile[900];

string braile[10] = {".***..", "*.....", "*.*...", "**....", "**.*..", "*..*..", "***...", "****..", "*.**..", ".**..."};

void to_braile(const string & str)
{
	int j, k, n = str.size() * 3;
	for(int i = 0; i < str.size(); ++i)
	{
		j = str[i] - '0';

		k = 3 * i;
		str_braile[k] = braile[j][0];
		str_braile[k + 1] = braile[j][1];
		str_braile[k + 2] = ' ';

		k += n;
		str_braile[k] = braile[j][2];
		str_braile[k + 1] = braile[j][3];
		str_braile[k + 2] = ' ';

		k += n;
		str_braile[k] = braile[j][4];
		str_braile[k + 1] = braile[j][5];
		str_braile[k + 2] = ' ';
	}

	str_braile[n - 1] = '\n';
	str_braile[2 * n - 1] = '\n';
	str_braile[3 * n - 1] = '\0';

	cout << str_braile << endl;
}

int find(const string & str)
{
	for(int i = 0; i < 10; ++i)
		if(str == braile[i]) return i;

	return -1;
}

void to_num(string & str, const int & s)
{
	str = "";
	string num;

	int k, n = s * 3;
	for(int i = 0; i < s; ++i)
	{
		num = "";

		k = 3 * i;
		num += str_braile[k];
		num += str_braile[k + 1];

		k += n;
		num += str_braile[k];
		num += str_braile[k + 1];

		k += n;
		num += str_braile[k];
		num += str_braile[k + 1];

		str += find(num) + '0';
	}

	cout << str << endl;
}

int main()
{
	int d;
	char c;
	string str;

	while(cin >> d, d)
	{
		cin >> c;
		if(c == 'S')
		{
			cin >> str;
			to_braile(str);
		}
		else
		{
			cin.getline(str_braile, 300);
			cin.getline(str_braile, 300);
			cin.getline(str_braile + d * 3, 300);
			cin.getline(str_braile + 2 * d * 3, 300);
			to_num(str, d);
		}
	}

	return 0;
}

