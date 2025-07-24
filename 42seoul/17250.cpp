#include <iostream>

using namespace std;

int N, M;
int C[100001];
int P[100001];

int find(int idx) {
	if (idx == P[idx]) {
		return idx;
	}
	P[idx] = find(P[idx]);
	return P[idx];
}

bool make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return false;
	}
	if (a > b) {
		P[a] = b;
		C[b] += C[a];
	} else {
		P[b] = a;
		C[a] += C[b];
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
		P[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		make_union(x, y);
		cout << C[find(x)] << '\n';
	}

	return 0;
}