#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int P, R;

int find(vector<int> &p, int idx) {
	if (p[idx] == idx) {
		return idx;
	}
	p[idx] = find(p, p[idx]);
	return p[idx];
}

bool makeUnion(vector<int> &p, int a, int b) {
	a = find(p, a);
	b = find(p, b);

	if (a == b) return false;
	if (a > b) {
		p[a] = b;
	} else {
		p[b] = a;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> P) {
		if (P == 0) {
			break;
		}
		cin >> R;
		vector<iii> V;
		vector<int> A(P + 1);
		for (int i = 1; i <= P; i++) {
			A[i] = i;
		}
		for (int i = 0; i < R; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			V.push_back({c, a, b});
		}
		sort(V.begin(), V.end());
		int answer = 0;
		for (auto [c, a, b] : V) {
			if (makeUnion(A, a, b)) {
				answer += c;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}