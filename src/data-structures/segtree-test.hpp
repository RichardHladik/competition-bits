class SegTree {
public:
	vector<ll> T;
	int n;
	SegTree(int n) : n(n), T(n, ZERO) {}

	void modify(int p, int v) {
		T[p] = v;
	}

	ll query(int l, int r) {
		ll res = ZERO;
		for (int i = l; i < r; i++)
			res = OP(res, T[i]);
		return res;
	}

	ll query2(int l, int r) {
		return query(l, r);
	}
};

