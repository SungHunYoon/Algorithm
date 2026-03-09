#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, C;
int X[2001], Y[2001], P[2001];
vector<iii> V;

int find(int idx) {
	if (P[idx] == idx) {
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

	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i];
		P[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int cost = ((X[i] - X[j]) * (X[i] - X[j])) + ((Y[i] - Y[j]) * (Y[i] - Y[j]));
			if (cost < C) continue;
			V.push_back({cost, i, j});
		}
	}
	sort(V.begin(), V.end());
	int answer = 0;
	for (auto [c, a, b] : V) {
		if (makeUnion(a, b)) {
			answer += c;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (find(i) != 1) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << answer << '\n';
	return 0;
}