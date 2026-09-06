#include <cstdio>

#define N 1'000'001

template <class T>
class linked_list
{
	struct node
	{
		T value;
		node * next = nullptr;
	};

	node * head = nullptr;

	public:

	virtual ~linked_list()
	{
		while(head)
		{
			node * d = head;
			head = head->next;
			delete d;
		}
	}

	void push_front(const T & v)
	{
		head = new node(v, head);
	}

	T suffix(const linked_list<T> & ll) const
	{
		node * na = head;
		node * nb = ll.head;

		int val = -1;
		while(na && nb && na->value == nb->value)
		{
			val = na->value;
			na = na->next;
			nb = nb->next;
		}

		return val;
	}
};

int main()
{
	int n, ha, hb;
	int val[N] = {};
	int next[N] = {};
	linked_list<int> lla;
	linked_list<int> llb;

	scanf("%d %d %d", &n, &ha, &hb);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", val + i, next + i);

	while(ha)
	{
		lla.push_front(val[ha]);
		ha = next[ha];
	}

	while(hb)
	{
		llb.push_front(val[hb]);
		hb = next[hb];
	}

	printf("%d\n", lla.suffix(llb));

	return 0;
}

