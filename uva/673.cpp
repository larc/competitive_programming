#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n, i;
	cin>>n;
	string s;
	getline(cin, s);
	while(n--)
	{
		getline(cin, s);
		stack<char> pila;
		for(i = 0; i < s.size(); ++i)
			if(s[i] == ')')
				if(!pila.empty() && pila.top() == '(')
					pila.pop();
				else
					break;
			else if(s[i] == ']')
				if(!pila.empty() && pila.top() == '[')
					pila.pop();
				else
					break;
			else pila.push(s[i]);
		if(i == s.size() && pila.empty()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
