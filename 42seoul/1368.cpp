#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N;
int P[302];
vector<iii> V;

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
		int n;
		cin >> n;
		P[i] = i;
		V.push_back({n, N + 1, i});
	}
	P[N + 1] = N + 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int n;
			cin >> n;
			if (n == 0) continue;
			V.push_back({n, i, j});
		}
	}
	sort(V.begin(), V.end());
	int answer = 0;
	for (auto [c, a, b] : V) {
		if (makeUnion(a, b)) {
			answer += c;
		}
	}
	cout << answer << '\n';

	return 0;
}