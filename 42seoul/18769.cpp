#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int T, R, C;

int find(vector<int> &P, int idx) {
	if (P[idx] == idx) {
		return idx;
	}
	P[idx] = find(P, P[idx]);
	return P[idx];
}

bool makeUnion(vector<int> &P, int a, int b) {
	a = find(P, a);
	b = find(P, b);
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

	cin >> T;
	while (T--) {
		cin >> R >> C;
		vector<int> P(R * C + 1);
		for (int i = 1; i <= R * C; i++) {
			P[i] = i;
		}
		vector<iii> V;
		for (int i = 1; i <= R; i++) {
			for (int j = 2; j <= C; j++) {
				int c;
				cin >> c;
				V.push_back({c, (i - 1) * C + j - 1, (i - 1) * C + j});
			}
		}
		for (int i = 2; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				int c;
				cin >> c;
				V.push_back({c, (i - 2) * C + j, (i - 1) * C + j});
			}
		}
		sort(V.begin(), V.end());
		int answer = 0;
		for (auto [c, a, b] : V) {
			if (makeUnion(P, a, b)) {
				answer += c;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}