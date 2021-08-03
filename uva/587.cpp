// 587 - There's treasure everywhere!

#include <cstdio>
#include <cmath>

struct point
{
	float x = 0, y = 0;

	point & operator += (const point & p)
	{
		x += p.x;
		y += p.y;
		return *this;
	}

	point & operator *= (const float & d)
	{
		x *= d;
		y *= d;
		return *this;
	}
};

float norm(const point & p)
{
	return sqrt(p.x * p.x + p.y * p.y);
}

int main()
{
	char line[256];
	point p, q;

	int d, m = 0;
	while(scanf("%s", line) && line[2] != 'D')
	{
		p = q = point();
		d = 0;
		for(int i = 0; line[i]; ++i)
		{
			const char & c = line[i];
			if(c >= '0' && c <= '9')
				d = 10 * d + c - '0';
			else if(c == ',' || c == '.')
			{
				q *= d / norm(q);
				p += q;
				q = point();
				d = 0;
			}
			else
			{
				switch(c)
				{
					case 'N': q.y = 1;	break;
					case 'S': q.y = -1;	break;
					case 'W': q.x = -1;	break;
					case 'E': q.x = 1;	break;
				}
			}
		}

		printf("Map #%d\n", ++m);
		printf("The treasure is located at (%.3f,%.3f).\n", p.x, p.y);
		printf("The distance to the treasure is %.3f.\n\n", norm(p));
	}

	return 0;
}

