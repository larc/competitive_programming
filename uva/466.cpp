#include <iostream>
#include <string>

using namespace std;

bool preservation(string * a, string * b, int n)
{
	for(int i = 0; i < n; i++)
		if(a[i] != b[i]) return 0;
	return 1;
}

string * rotate90(string * a, int n)
{
	string * s = new string[n];
	for(int i = 0; i < n; i++)
		s[i] = a[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			s[j][n - i - 1] = a[i][j];
	return s;
}

string * rotate180(string * a, int n)
{
	string * s = new string[n];
	for(int i = 0; i < n; i++)
		s[i] = a[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			s[n - i - 1][n - j - 1] = a[i][j];
	return s;
}

string * rotate270(string * a, int n)
{
	string * s = new string[n];
	for(int i = 0; i < n; i++)
		s[i] = a[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			s[n - j - 1][i] = a[i][j];
	return s;
}

string * vreflection(string * a, int n)
{
	string * s = new string[n];
	for(int i = 0; i < n; i++)
		s[i] = a[i];
	for(int i = 0; i < n; i++)
		s[n - i - 1] = a[i];
	return s;
}

void print(string * s, int n)
{
	for(int i = 0; i < n; i++)
		cout<<s[i]<<endl;
	cout<<endl;
}

int main()
{
	int n, i, p;
	string a[10], b[10], * s;
	p = 1;
	while(cin>>n)
	{
		for(i = 0; i < n; i++)
			cin>>a[i]>>b[i];

//		print(a, n);
//		print(vreflection(a, n), n);
		if(preservation(a, b, n))
			cout<<"Pattern "<<p++<<" was preserved."<<endl;
		else if(preservation(rotate90(a, n), b, n))
			cout<<"Pattern "<<p++<<" was rotated 90 degrees."<<endl;
		else if(preservation(rotate180(a, n), b, n))
			cout<<"Pattern "<<p++<<" was rotated 180 degrees."<<endl;
		else if(preservation(rotate270(a, n), b, n))
			cout<<"Pattern "<<p++<<" was rotated 270 degrees."<<endl;
		else if(preservation(s = vreflection(a, n), b, n))
			cout<<"Pattern "<<p++<<" was reflected vertically."<<endl;
		else if(preservation(rotate90(s, n), b, n))
			cout<<"Pattern "<<p++<<" was reflected vertically and rotated 90 degrees."<<endl;
		else if(preservation(rotate180(s, n), b, n))
			cout<<"Pattern "<<p++<<" was reflected vertically and rotated 180 degrees."<<endl;
		else if(preservation(rotate270(s, n), b, n))
			cout<<"Pattern "<<p++<<" was reflected vertically and rotated 270 degrees."<<endl;
		else
			cout<<"Pattern "<<p++<<" was improperly transformed."<<endl;
	}

	return 0;
}
