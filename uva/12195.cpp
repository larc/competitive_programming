// 12195 - Jingle Composing

#include <cstdio>

int main()
{
	double note[256];
	note['W'] = 1.;
	note['H'] = 1. / 2;
	note['Q'] = 1. / 4;
	note['E'] = 1. / 8;
	note['S'] = 1. / 16;
	note['T'] = 1. / 32;
	note['X'] = 1. / 64;

	char line[201];
	int m;
	double d;

	while(scanf("%s", line) && line[0] != '*')
	{
		m = 0;
		for(int i = 1; line[i]; ++i)
		{
			d = 0;
			while(line[i] != '/')
				d += note[line[i++]];
			
			if(d == 1) m++;
		}

		printf("%d\n", m);
	}

	return 0;
}

