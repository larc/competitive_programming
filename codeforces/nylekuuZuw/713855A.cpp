#include <cstdio>

template <class T>
class linked_list
{
	struct node
	{
		T value;
		node * next = nullptr;
	};

	node * head = nullptr;
	int size = 0;

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
		++size;
	}

	T middle() const
	{
		int m = (size >> 1) + (size & 1);
		node * n = head;
		while(--m) n = n->next;
		return n->value;
	}
};

int main()
{
	int n, v;
	linked_list<int> lli;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &v);
		lli.push_front(v);
	}

	printf("%d\n", lli.middle());

	return 0;
}

