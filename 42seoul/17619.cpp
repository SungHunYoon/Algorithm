#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, Q;
int P[100001];
iii A[100001];

int find(int idx) {
	if (idx == P[idx]) {
		return idx;
	}
	P[idx] = find(P[idx]);
	return P[idx];
}

bool makeUnion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return false;
	}
	if (a > b) {
		P[a] = b;
	} else {
		P[b] = a;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		A[i] = {a, b, i};
		P[i] = i;
	}
	sort(A + 1, A + N + 1);
	int c = get<2>(A[1]);
	int e = get<1>(A[1]);
	for (int i = 2; i <= N; i++) {
		auto [x1, x2, n] = A[i];
		if (e >= x1) {
			makeUnion(c, n);
			e = max(e, x2);
		} else {
			c = n;
			e = x2;
		}
	}
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b)) {
			cout << "0\n";
		} else {
			cout << "1\n";
		}
	}
	return 0;
}