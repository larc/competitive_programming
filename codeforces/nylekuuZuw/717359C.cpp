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

		operator bool ()
		{
			return n != nullptr;
		}

		iterator operator ++ ()
		{
			n = tree.PS(n->key, true);
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

	iterator predessor(const K & key)
	{
		return {*this, PS(key, false)};
	}

	iterator successor(const K & key)
	{
		return {*this, PS(key, true)};
	}


protected:

	bool search(node **& n, const K & key)
	{
		n = &root;
		while(*n && (*n)->key != key)
			n = &(*n)->child[(*n)->key < key];
		return *n && (*n)->key == key;
	}

	node ** left_max(node * n)
	{
		return LRM(n, false);
	}

	node ** right_min(node * n)
	{
		return LRM(n, true);
	}

	node ** LRM(node * n, const bool R)
	{
		node ** lrm = &n->child[R];
		while(*lrm && (*lrm)->child[!R])
			lrm = &(*lrm)->child[!R];
		return lrm;
	}

	node * PS(const K & key, const bool R)
	{
		node * n = root;
		node * ps = nullptr;
		while(n && n->key != key)
		{
			bool b =((n->key > key) && R) || ((n->key < key) && !R);
			if(b) ps = n;
			n = n->child[!b && R];
		}
		return n && n->child[R] ? *LRM(n, R) : ps;
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

int main()
{
	int n, k, t, a;
	std::vector<int> A;
	A.reserve(1'000'000);

	bool find = false;
	//bst<int, int> W;			// time limit need balancing
	std::map<int, int> W;		// pass all points

	scanf("%d %d %d", &n, &k, &t);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);

		int out = i - k - 1;
		if(out >= 0 && !--W[A[out]])
			W.erase(A[out]);	// BST std::map
			//W.remove(A[out]);

		/*
		auto p = W.predessor(a);
		auto s = W.successor(a);
		if(p != W.end() && abs((*p).first - a) <= t)
			find = true;
		if(s != W.end() && abs((*s).first - a) <= t)
			find = true;
		*/

		// BST std::map
		auto p = W.lower_bound(a);
		auto s = W.upper_bound(a);
		if(p != W.end() && abs((*p).first - a) <= t)
			find = true;
		if(s != W.end() && abs((*s).first - a) <= t)
			find = true;

		++W[a];
		A[i] = a;
	}

	printf("%s\n", find ? "SI" : "NO");

	return 0;
}
