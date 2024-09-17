// 1451 - Broken Keyboard

#include <string>
#include <iostream>
#include <list>


using namespace std;

int main()
{
	string line, r, w;

	while(getline(cin, line))
	{
		list<char> lista;
		list<char>::iterator il = lista.begin();
		for(char c: line)
			if(c == '[')
				il = lista.begin();
			else if(c == ']')
				il = lista.end();
			else
				lista.insert(il, c);

		for(char c: lista)
			cout << c;
		cout << endl;
	}

	return 0;
}

