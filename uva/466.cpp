// 466 - Mirror, Mirror

#include <iostream>
#include <string>

using namespace std;


bool preservation(string * a, string * b, int n)
{
	for(int i = 0; i < n; ++i)
		if(a[i] != b[i])
			return 0;

	return 1;
}

string * rotate90(string * a, string * s, int n)
{
	for(int i = 0; i < n; ++i)
		s[i] = a[i];

	for(int i = 0; i < n; ++i)
	for(int j = 0; j < n; ++j)
		s[j][n - i - 1] = a[i][j];

	return s;
}

string * vreflection(string * a, string * s, int n)
{
	for(int i = 0; i < n; ++i)
		s[i] = a[i];
	for(int i = 0; i < n; ++i)
		s[n - i - 1] = a[i];
	return s;
}

void print(string * s, int n)
{
	for(int i = 0; i < n; ++i)
		cout << s[i] << endl;
	cout << endl;
}


enum transform_t { PP, R90, R180, R270, VP, VR90, VR180, VR270, IP };

transform_t solve(string * a, string * b, int n)
{
	static string s[10];
	if(preservation(a, b, n))
		return PP;
	if(preservation(rotate90(a, s, n), b, n))
		return R90;
	if(preservation(rotate90(s, a, n), b, n))
		return R180;
	if(preservation(rotate90(a, s, n), b, n))
		return R270;

	rotate90(s, a, n);
	if(preservation(vreflection(a, s, n), b, n))
		return VP;
	if(preservation(rotate90(s, a, n), b, n))
		return VR90;
	if(preservation(rotate90(a, s, n), b, n))
		return VR180;
	if(preservation(rotate90(s, a, n), b, n))
		return VR270;

	return IP;
}

int main()
{
	string a[10], b[10];

	int n, p = 0;
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
			cin >> a[i] >> b[i];

		cout << "Pattern " << ++p;
		switch(solve(a, b, n))
		{
			case PP:
				cout << " was preserved." << endl;
				break;
			case R90:
				cout << " was rotated 90 degrees." << endl;
				break;
			case R180:
				cout << " was rotated 180 degrees." << endl;
				break;
			case R270:
				cout << " was rotated 270 degrees." << endl;
				break;
			case VP:
				cout << " was reflected vertically." << endl;
				break;
			case VR90:
				cout << " was reflected vertically and rotated 90 degrees." << endl;
				break;
			case VR180:
				cout << " was reflected vertically and rotated 180 degrees." << endl;
				break;
			case VR270:
				cout << " was reflected vertically and rotated 270 degrees." << endl;
				break;
			default:
				cout << " was improperly transformed." << endl;
				break;
		}
	}

	return 0;
}

