#include "base.hpp"

#define ZERO 0
#define OP(a, b) ((a) + (b))
#ifdef TEST
#include "segtree-test.hpp"
#else
#include "segtree.hpp"
#endif

int main(void) {
	int m, n;
	cin >> n >> m;

	SegTree st(n);
	FOR(i, m){
		string o;
		int l, r;
		cin >> o >> l >> r;
		if (o[0] == '+'){
			ll v;
			cin >> v;
			assert(l == r);
			st.modify(l, v);
		} else {
			cout << st.query(l, r) << '\n';
		}
	}
}
