// 10491 - Cows and Cars

#include <cstdio>

int main()
{
	double ncows, ncars, nshow, ndoors;

	while(scanf("%lf %lf %lf", &ncows, &ncars, &nshow) != EOF)
	{
		ndoors = ncows + ncars;
		printf("%.5lf\n", ncars * (ndoors - 1) / (ndoors * (ndoors - nshow - 1)));
	}

	return 0;
}

