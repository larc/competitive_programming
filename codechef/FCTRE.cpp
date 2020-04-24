#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

#define NP 1000
#define N 100001
#define M 18

#define mod(x) (x) % 1000000007

typedef long long ll;
typedef std::map<ll, ll> mii;

std::vector<int> G[N];
ll A[N];
mii factors[N];

int parent[N];
int level[N], idx[N];
int euler[N << 1];
int st[M][N << 1];

ll primes[NP], np;

void sieve()
{
	bool not_prime[NP] = {};

	np = 0;
	primes[np++] = 2;

	for(ll i = 3; i < NP; i += 2)
	{
		if(!not_prime[i])
		{
			primes[np++] = i;
			for(ll j = i * i; j < NP; j += i << 1)
				not_prime[j] = 1;
		}
	}
}

void update_factors(const int & u)
{
	mii & fout = factors[u] = factors[parent[u]];

	ll n = A[u];
	for(int i = 0; i < np && primes[i] * primes[i] <= n; i++)
	{
		const ll & p = primes[i];
		while(!(n % p))
		{
			fout[p]++;
			n /= p;
		}
	}

	if(n > 1) fout[n]++;
}

void dfs(const int & u, int & i)
{
	idx[u] = i;
	euler[i++] = u;

	for(const int & v: G[u])
		if(level[v] == -1)
		{
			parent[v] = u;
			level[v] = level[u] + 1;
			
			update_factors(v);
			
			dfs(v, i);
			euler[i++] = u;
		}
}

void init_st(const int & m)
{
	for(int i = 0; i < m; i++)
		st[0][i] = i;
	
	int k;
	for(int i = 1; (1 << i) <= m; i++)
	{
		k = 1 << (i - 1);
		for(int j = 0; j + (1 << i) - 1 < m; j++)
		{
			const int & u = st[i - 1][j];
			const int & v = st[i - 1][j + k];
			st[i][j] = level[euler[u]] < level[euler[v]] ? u : v;
		}
	}
}

int lca(int a, int b)
{
	if(idx[b] < idx[a]) return lca(b, a);
	
	a = idx[a];
	b = idx[b];
	int k = log2(b - a + 1);

	const int & i = st[k][a];
	const int & j = st[k][b - (1 << k) + 1];

	return level[euler[i]] < level[euler[j]] ? euler[i] : euler[j];	
}

ll query(const int & u, const int & v)
{
	static mii F;
	F.clear();

	int w = lca(u, v);
	int pw = parent[w];

	for(auto & p: factors[u])
		F[p.first] += p.second - factors[w][p.first];
	
	for(auto & p: factors[v])
		F[p.first] += p.second - factors[pw][p.first];

	ll ans = 1;
	for(auto & p: F)
		ans = mod(ans * (p.second + 1));

	return ans;
}

int main()
{
	int n_cases, n, m, q, u, v;

	sieve();	// printf("np %d\n", np);

	scanf("%d", &n_cases);
	while(n_cases--)
	{
		scanf("%d", &n);
		for(int i = 1; i < n; i++)
		{
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		for(int i = 1; i <= n; i++)
			scanf("%lld", A + i);

		memset(level, -1, sizeof(level));
		level[1] = parent[1] = 0;

		update_factors(1);
		dfs(1, m = 0); init_st(m);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			printf("%lld\n", query(u, v));
		}
		
		for(int i = 1; i <= n; i++)
			G[i].clear();
	}

	return 0;
}

