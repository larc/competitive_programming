#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define NS 100000

using namespace std;

struct street
{
	int u, v, L;	// u -> v
	char name[32];
	int traffic = 0;						// max num of cars at some time

} streets[100000];						// input: street values

map<string, int> id_street;				// input: street name -> id	
vector<int> cars[1000];					// input: car's path

vector<int> intersections[100000];		// step 1: fill with in streets in some path

int main()
{
	char stname[32];
	int D, I, S, V, F, P;
	scanf("%d %d %d %d %d", &D, &I, &S, &V, &F);

	for(int i = 0; i < S; i++)
	{
		street & st = streets[i];
		scanf("%d %d %s %d", &st.u, &st.v, st.name, &st.L);

		id_street[st.name] = i;
	}

	for(int i = 0; i < V; i++)
	{
		scanf("%d", &P);

		vector<int> & vcar = cars[i];
		vcar.reserve(P);
	
		while(P--)
		{
			scanf("%s", stname);
			vcar.push_back(id_street[stname]);
		}
	}
	
	int time, max_path_time = 0;
	size_t max_stops = 0;

	// step 1:
	for(int i = 0; i < V; i++)
	{
		time = 0;

		vector<int> & vcar = cars[i];
		for(int j = 0; j < vcar.size() - 1; j++)
		{
			street & st = streets[vcar[j]];
			if(!st.traffic)
				intersections[st.v].push_back(vcar[j]);
			st.traffic++;
			time += st.L;
		}

		time -= streets[vcar.front()].L + streets[vcar.back()].L;
		max_path_time = max(max_path_time, time);

		max_stops = max(max_stops, vcar.size() - 1);
	}
	
	time = max((D - max_path_time) / max_stops, 1lu);		// max time per stop loop

	fprintf(stderr, "streets: %d\n", S);
	fprintf(stderr, "intersections: %d\n", I);
	fprintf(stderr, "cars: %d\n", V);
	fprintf(stderr, "D: %10d, max_path_time: %10d\n", D, max_path_time);
	fprintf(stderr, "time: %10d, max_stops: %10lu\n", time, max_stops);

	int sum, A = 0;
	for(int i = 0; i < I; i++)
		A += intersections[i].size() > 0;
	
	printf("%d\n", A);

	// adding traffic solution
	for(int i = 0; i < I; i++)
	{
		vector<int> & vint = intersections[i];
		if(vint.size())
		{
			printf("%d\n", i);
			printf("%lu\n", vint.size());

			sort(vint.begin(), vint.end(), [](const int & i, const int & j)
			{
				return streets[i].traffic > streets[j].traffic;
			});

			sum = 0;
			for(const int & s: vint)
				sum += streets[s].traffic;

			for(const int & s: vint)
				printf("%s %d\n", streets[s].name, max(streets[s].traffic * time / sum, 1));
		}
	}

	return 0;
}

