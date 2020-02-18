#include "base.hpp"

vector <ll> tree;
int n, t;

ll _q(int l, int r, int tl, int tr, ll c, int pos)
{
	if (r < l || l < tl || r > tr)
		return 0;

	tree[pos] += c;
	if (l == tl && r == tr)
		return tree[pos];

	int m = (tl + tr) / 2;
	return _q(l, min(r, m), tl, m, c, pos * 2) + _q(max(m + 1, l), r, m + 1, tr, c, pos * 2 + 1);
}

ll update(int l, int r, ll v)
{
	return _q(l, r, 0, t - 1, v, 1);
}

ll query(int l, int r)
{
	return update(l, r, 0);
}

int main(void)
{
	int m;
	cin >> n >> m;
	for (t = 1; t < n; t *= 2)
		;

	tree.resize(2 * t);
	FOR(i, m){
		string o;
		int l, r;
		cin >> o >> l >> r;
		if (o[0] == '+'){
			ll v;
			cin >> v;
			update(l, r, v);
		} else {
			cout << query(l, r) << '\n';
		}
	}
}
