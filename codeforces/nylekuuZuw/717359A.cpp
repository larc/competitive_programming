#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>


template <class K, class V>
class bst
{
	struct node
	{
		K key;
		V value;
		node * child[2] = {};
	};

	node * root = nullptr;


public:

	virtual ~bst()
	{
		free(root);
	}

	V & operator [] (const K & key)
	{
		node ** n = nullptr;
		if(!search(n, key))
			*n = new node(key, {});

		return (*n)->value;
	}

	bool search(const K & key)
	{
		node ** n;
		return search(n, key);
	}

	bool insert(const K & key, const V & value)
	{
		node ** n = nullptr;
		if(search(n, key))
			return false;

		*n = new node(key, value);

		return true;
	}

	bool remove(const K & key)
	{
		node ** n = nullptr;
		if(search(n, key))
			return false;

		if(left(*n) && right(*n))
		{
			node ** s = right_min(*n);
			left(*s) = left(*n);
			std::swap(right(*n), right(*s));
			std::swap(*n, *s);
			n = s;
		}

		node * rm = *n;
		*n = (*n)->child[right(*n) != nullptr];
		delete rm;

		return true;
	}

	void inorder(const V & cond = INFINITY)
	{
		inorder(root, cond);
	}

	struct iterator
	{
		bst & tree;
		node * n = nullptr;

		iterator & operator ++ ()
		{
			n = tree.successor(n->key);
			return *this;
		}

		std::pair<const K&, V&> operator * ()
		{
			return {n->key, n->value};
		}

		bool operator != (const iterator & iter)
		{
			return n != iter.n;
		}
	};

	iterator begin()
	{
		node * n = root;
		while(n && left(n))
			n = left(n);
		return {*this, n};
	}

	iterator end()
	{
		return {*this, nullptr};
	}

protected:

	bool search(node **& n, const K & key)
	{
		n = &root;
		while(*n && (*n)->key != key)
			n = &(*n)->child[(*n)->key < key];
		return *n && (*n)->key == key;
	}

	node ** right_min(node * n)
	{
		node ** s = &right(n);
		while(*s && left(*s))
			s = &left(*s);
		return s;
	}

	node * successor(const K & key)
	{
		node * n = root;
		node * succ = nullptr;
		while(n && n->key != key)
		{
			if(n->key > key)
			{
				succ = n;
				n = n->child[0];
			}
			else n = n->child[1];
		}

		return right(n) ? *right_min(n) : succ;
	}

	void inorder(node * n, const V & cond)
	{
		if(!n) return;

		inorder(left(n), cond);
		if(n->value == cond) printf("%d ", n->key);
		inorder(right(n), cond);
	}

	void free(node * n)
	{
		if(!n) return;
		free(left(n));
		free(right(n));
		delete n;
	}

	node *& left(node *& n)
	{
		return n->child[0];
	}
	node *& right(node *& n)
	{
		return n->child[1];
	}
};


int hash(int key, const size_t m)
{
	return key % m;
}

template <class K, class V>
class table_hash
{
	struct node
	{
		K key;
		V value;
		node * next = nullptr;
	};

	std::vector<node *> table;

public:
	table_hash(int n = 1'000'003)
	{
		table.resize(n);
	}
	virtual ~table_hash()
	{
		for(auto head: table)
			while(head)
			{
				node * del = head;
				head = head->next;
				delete del;
			}
	}
	V & operator [] (const K & key)
	{
		node ** n = &table[hash(key, size(table))];
		while(*n && (*n)->key != key)
			n = &(*n)->next;
		if(!*n) *n = new node(key, {});
		return (*n)->value;
	}
};

int main()
{
	int n, a;
	table_hash<int, int> M;
	std::vector<int> ans;
	ans.reserve(1'000'000);

	//bst<int, int> M;			// partial points 2 (issue: unbalance)
	//std::map<int, int> M;		// pass all points

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		if(++M[a] == 2)
			ans.push_back(a);
	}

// 	TABLE HASH 
	std::sort(begin(ans), end(ans));
	for(int k: ans)
		printf("%d ", k);
	printf("\n");

// 	BST inorder conditional
//	mytree.inorder(2);
//	printf("\n");

// 	BST iterator
//	for(auto [k, v]: mytree)
//		if(v == 2) printf("%d ", k);
//	printf("\n");

	return 0;
}
