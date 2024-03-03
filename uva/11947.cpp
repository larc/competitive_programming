// 11947 - Cancer or Scorpio

#include <cstdio>

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(const int y)
{
	return (!(y & 3) && (y % 100)) || !(y % 400);
}

struct date_t
{
	int m, d, y;

	void init(const int n = 0)
	{
		m = n / 1000000;
		d = (n / 10000) % 100;
		y = n % 10000;
	}

	void print()
	{
		printf("%02d/%02d/%4d", m, d, y);
	}

	int day()
	{
		if(m > 2 && is_leap(y)) return month[m - 1] + d + 1;
		return month[m - 1] + d;
	}

	date_t & operator += (const int days)
	{
		d = days + day();
		if(is_leap(y) && d > 366)
		{
			d %= 366;
			y++;
		}
		if(!is_leap(y) && d > 365)
		{
			d %= 365;
			y++;
		}

		bool leap = is_leap(y);
		for(m = 0; d > month[m] + (m >= 2 ? leap : 0); ++m);
		if(m > 1) d %= month[m - 1] + ((m > 2) ? leap : 0);

		return *this;
	}
};

int d_sign [] = {0, 21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23};

const char * sign [] = {"capricorn",
						"aquarius",
						"pisces",
						"aries",
						"taurus",
						"gemini",
						"cancer",
						"leo",
						"virgo",
						"libra",
						"scorpio",
						"sagittarius",
						"capricorn"};

const char * get_sign(date_t & d)
{
	return sign[d.m - (d.d < d_sign[d.m])];
}

int main()
{
	date_t d;
	for(int i = 1; i <= 12; ++i)
		month[i] += month[i - 1];

	int date, cases;
	scanf("%d", &cases);
	for(int c = 1; c <= cases; ++c)
	{
		scanf("%d", &date);
		d.init(date);

		printf("%d ", c);
		d += 280;
		d.print();
		printf(" %s\n", get_sign(d));
	}

	return 0;
}

