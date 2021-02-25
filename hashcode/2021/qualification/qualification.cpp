#include <cstdio>
#include <string>
#include <vector>
#include <map>

#define NS 100000

using namespace std;

struct street
{
	int u, v, L;	// u -> v
	char name[32];
	bool on = false;

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
	
	// step 1:
	for(int i = 0; i < V; i++)
	{
		vector<int> & vcar = cars[i];
		for(const int & s: vcar)
		{
			street & st = streets[s];
			if(!st.on)
			{
				st.on = true;
				intersections[st.v].push_back(s);
			}
		}
	}
	
	int A = 0;
	for(int i = 0; i < I; i++)
		A += intersections[i].size() > 0;
	
	printf("%d\n", A);

	// naive solution
	for(int i = 0; i < I; i++)
	{
		vector<int> & vint = intersections[i];
		if(vint.size())
		{
			printf("%d\n", i);
			printf("%lu\n", vint.size());

			for(const int & s: vint)
				printf("%s %d\n", streets[s].name, 1);
		}
	}

	return 0;
}

