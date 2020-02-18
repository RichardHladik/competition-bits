class SegTree {
public:
	vector<ll> T;
	int n;
	SegTree(int m) {
		n = 1;
		while (n < m)
			n *= 2;
		T.resize(2 * n, ZERO);
	}

	void modify(int p, int v) {
		for (T[p += n] = v; p > 1; p /= 2)
			T[p / 2] = OP(T[p], T[p^1]);
	}

	ll query(int l, int r) {
		ll res = ZERO;
		for (l += n, r += n; l < r; l /= 2, r /= 2){
			if (l % 2) res = OP(res, T[l++]);
			if (r % 2) res = OP(res, T[--r]);
		}

		return res;
	}

	ll query2(int l, int r) {
		return query2(l, r, 0, n, 1);
	}

	ll query2(int l, int r, int tl, int tr, int pos) {
		l = std::max(l, tl);
		r = std::min(r, tr);
		if (r <= l)
			return ZERO;
		if (l == tl && r == tr)
			return T[pos];

		int m = (tl + tr) / 2;
		return OP(
			query2(l, min(r, m), tl, m, pos * 2),
			query2(max(m, l), r, m, tr, pos * 2 + 1)
		);
	}
};

