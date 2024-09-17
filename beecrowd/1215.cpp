// 1215 - Andy's First Dictionary

#include <string>
#include <iostream>
#include <set>


using namespace std;

inline bool isletter(char x, char & c)
{
	if((x > 'z' || x < 'a') && (x > 'Z' || x < 'A')) return 0;
	c = x < 'a' ? x - 'A' + 'a' : x;
	return 1;
}

inline void word(string & s, set<string> & dic)
{
	string w = "";
	char c;
	for(unsigned int i = 0; i < s.size(); ++i)
		if(isletter(s[i], c)) w += c;
		else if(w != "")
		{
			dic.insert(w);
			w = "";
		}
	if(w != "")
		dic.insert(w);
}

int main()
{
	string str;
	set<string> dic;

	while(cin >> str)
		word(str, dic);

	for(auto & s: dic)
		cout << s << endl;

	return 0;
}

