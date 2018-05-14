// 1203 - Argus

#include <cstdio>
#include <queue>

struct query
{
	int qnum, period;
};

bool operator < (const query & a, const query & b)
{
	if(a.period == b.period) return a.qnum > b.qnum;
	return a.period > b.period;
}

int main()
{
	query q;
	int periods[3001];
	char str[10];
	
	std::priority_queue<query> report;
	while(scanf("%s", str), str[0] != '#')
	{
		scanf("%d %d", &q.qnum, &q.period);
		periods[q.qnum] = q.period;
		
		report.push(q);
	}
	
	int k;
	scanf("%d", &k);
	while(k--)
	{
		q = report.top();
		report.pop();
		
		printf("%d\n", q.qnum);
		
		q.period += periods[q.qnum];
		report.push(q);
	}

	return 0;
}

