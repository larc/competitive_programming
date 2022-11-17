#include <cstdio>
#include <vector>

struct bst
{
	struct node
	{
		int value;
		node * child[2] = {};

		node(const int & val): value(val) {}
		~node()
		{
			delete child[0];
			delete child[1];
		}
	};

	node * root = nullptr;

	~bst()
	{
		delete root;
	}

	node ** find(const int & val)
	{
		node ** n = &root;
		while(*n)
		{
			if((*n)->value == val)
				break;

			n = &(*n)->child[(*n)->value < val];
		}

		return n;
	}

	bool insert(const int & val)
	{
		node ** n = find(val);
		if(*n) return false;

		*n = new node(val);

		return true;
	}

	bool operator == (const bst & t)
	{
		return equal(root, t.root);
	}

	bool equal(const node * a, const node * b) const
	{
		if(a && b)
			return equal(a->child[0], b->child[0]) && equal(a->child[1], b->child[1]);

		return !a && !b;
	}
};

int main()
{
	int n, k, v, count;
	bool repeat;

	std::vector<bst> vbst;
	vbst.reserve(50);

	while(scanf("%d %d", &n, &k) != EOF)
	{
		vbst.clear();
		vbst.resize(n);

		count = 0;
		for(int i = 0; i < n; ++i)
		{
			bst & t = vbst[i];
			for(int j = 0; j < k; ++j)
			{
				scanf("%d", &v);
				t.insert(v);
			}

			repeat = false;
			for(int j = 0; j < i; ++j)
				if(t == vbst[j])
				{
					repeat = true;
					break;
				}

			if(!repeat) ++count;
		}

		printf("%d\n", count);
	}

	return 0;
}

