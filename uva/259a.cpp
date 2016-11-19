/**
 * Tittle:	259 - Software Allocation
 * Author:	Cheng-Shih, Wong
 * Date:	2015/05/05
 */

// include files
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )
#define N 50
#define INF 1e5

typedef queue<int> QI;

// declarations
char cmd[50];
int n, usrcnt;
int S, T;

// functions
int f[N][N];
int c[N][N];

int maxflow( int n, int s, int t )
{
	static int i, u, v, flow, d[N], pre[N];
	static bool mk[N];
	flow = 0;
	clr( f, 0 );

	while( true ) {
		clr( mk, false ); clr( d, 0 );
		QI que;
		que.push(s); mk[s] = true; d[s] = INF;

		while( !que.empty() && !mk[t] ) {
			u = que.front(); que.pop();
			// printf( "# from %d\n", u );
			for( v=0; v<=n; ++v ) if( !mk[v] && f[u][v]<c[u][v] ) {
				// printf( "# to %d\n", v );
				mk[v] = true; que.push(v); pre[v] = u;

				if( d[u] < c[u][v]-f[u][v] ) d[v] = d[u];
				else d[v] = c[u][v]-f[u][v];
			}
		}

		if( !mk[t] ) break;
		flow += d[t];
		// printf( "## d[t] = %d\n", d[t] );

		for( u=t; u!=s; ) {
			v = u; u = pre[v];
			f[u][v] += d[t];
			f[v][u] = -f[u][v];
		}
	}

	return flow;
}

void parse( char *input ) 
{
	static int l;
	static int u, num, v;

	// printf( "## %s\n", input );

	l = strlen( input );

	u = input[0]-'A';
	num = input[1]-'0';

	usrcnt += num;
	c[S][u] += num;
	// printf( "Add S to %c, %d flow\n", u+'A', num );

	FOR( i, 3, l-2 ) {
		// printf( "Add %c to %d, 1 flow\n", u+'A', input[i]-'0' );
		c[u][input[i]-'0'+26] = 1;
	}
}

void init()
{
	clr( c, 0 );
	usrcnt = 0;
	FOR( i, 26, 35 )
		c[i][T] = 1;
}

// main function
int main( void )
{
	int mf;
	int v;
	S = 36;
	T = 37;
	n = 37;
	
	// input
	while( gets(cmd) && cmd[0] ) {
		init();
		parse(cmd);

		while( gets(cmd) && cmd[0] ) 
			parse(cmd);

		// solve
		mf = maxflow( n, S, T );
		// printf( "@@ %d\n", mf );

		// output
		if( mf != usrcnt ) puts("!");
		else {
			FOR( u, 26, 35 ) {
				for( v=0; v<=25 && !f[v][u]; ++v );

				if( v > 25 ) putchar('_');
				else putchar(v+'A');
			}
			putchar('\n');
		}
	}
	
	return 0;
}
