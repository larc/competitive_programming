#include <string>
#include <iostream>
#include <list>

using namespace std;

int main()
{
	string line, r, w;
	int i;
	while(getline(cin, line))
	{
		list<char> lista;
		list<char>::iterator il = lista.begin();
		for(i = 0; i < line.size(); i++)
			if(line[i] == '[')
				il = lista.begin();
			else if(line[i] == ']')
				il = lista.end();
			else
				lista.insert(il, line[i]);
				
		for(il = lista.begin(); il != lista.end(); il++)
			cout<<*il;
		cout<<endl;
	}
	return 0;
}
