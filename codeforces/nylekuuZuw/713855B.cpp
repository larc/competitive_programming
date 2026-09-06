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
	int n_nodes = 0;

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
		++n_nodes;
	}

	int remove_all(const T & x)
	{
		node ** n = &head;
		while(*n)
		{
			node * d = *n;
			if(d->value == x)
			{
				--n_nodes;
				*n = d->next; 
				delete d;
			}
			else n = &d->next;
		}
		return n_nodes;
	}

	void print() const
	{
		print(head);
		printf("\n");
	}

	int size() const
	{
		return n_nodes;
	}

	private:

	void print(node * n) const
	{
		if(!n) return;
		print(n->next);
		printf("%d ", n->value);
	}
};

int main()
{
	int n, x, v;
	linked_list<int> lli;

	scanf("%d %d", &n, &x);
	while(n--)
	{
		scanf("%d", &v);
		lli.push_front(v);
	}

	printf("%d\n", lli.remove_all(x));
	lli.print();

	return 0;
}

