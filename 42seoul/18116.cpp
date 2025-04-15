#include <iostream>

using namespace std;

int N;
int P[1000001];
int C[1000001];

int find(int idx) {
	if (idx == P[idx])
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

bool make_union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b)
		return false;
	if (a > b) {
		P[a] = b;
		C[b] += C[a];
	}
	else {
		P[b] = a;
		C[a] += C[b];
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= 1000000; i++) {
		P[i] = i;
		C[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		char c;
		int a, b;
		cin >> c;
		if (c == 'I') {
			cin >> a >> b;
			make_union(a, b);
		} else {
			cin >> a;
			cout << C[find(a)] << '\n';
		}
	}
	return 0;
}