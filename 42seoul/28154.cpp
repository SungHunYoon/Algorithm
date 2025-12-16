#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N;
string S[101];
vector<iii> M;

bool matchX(int x) {
	int y = 0;
	for (int i = 0; i < M.size(); i++) {
		auto [d, s, t] = M[i];
		if ((s + x * t) % d != 0) {
			return false;
		}
		if (y == 0) {
			y = (s + x * t) / d;
		}
		if (y != (s + x * t) / d) {
			return false;
		}
	}
	return true;
}

int findX() {
	vector<int> X;
	for (int i = 0; i < M.size(); i++) {
		for (int j = i + 1; j < M.size(); j++) {
			auto [d1, s1, t1] = M[i];
			auto [d2, s2, t2] = M[j];
			int A = d2 * t1 - d1 * t2;
			int B = d1 * s2 - d2 * s1;
			if (A != 0) {
				if (B % A == 0 && B / A > 0) {
					if (matchX(B / A)) {
						X.push_back(B / A);
					}
				}
			} else {
				if (B != 0) {
					return -1;
				}
			}
		}
	}
	X.push_back(1);
	sort(X.begin(), X.end());
	for (auto x : X) {
		if (matchX(x)) {
			return x;
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	int level = 0;
	for (int i = 0; i < N; i++) {
		int sCnt = 0, tCnt = 0;
		for (auto s : S[i]) {
			if (s == 's') {
				sCnt++;
			} else if (s == 't') {
				tCnt++;
			} else if (s == '{') {
				if (level != 0) M.push_back({level, sCnt, tCnt});
				level++;
			} else {
				level--;
				if (level != 0) M.push_back({level, sCnt, tCnt});
			}
		}
	}
	cout << findX() << '\n';
	return 0;
}