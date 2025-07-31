#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int ,int ,int>;
using ii = tuple<int, int>;

int N;
int A[201][201];
vector<iii> E;
int P[201];

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

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		P[i] = i;
	}
	int size = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (A[i][j] < 0) {
				makeUnion(i, j);
				size += A[i][j] * -1;
			} else {
				E.push_back({A[i][j], i, j});
			}
		}
	}
	vector<ii> B;
	sort(E.begin(), E.end());
	for (auto [c, a, b] : E) {
		if (makeUnion(a, b)) {
			size += c;
			B.push_back({a, b});
		}
	}
	cout << size << ' ' << B.size() << '\n';
	for (auto [a, b] : B) {
		cout << a << ' ' << b << '\n';
	}

	return 0;
}