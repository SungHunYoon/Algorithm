#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
using iii = tuple<int, int, int>;

int N;
vector<iii> E;
int P[51];

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
	if (a > b)
		P[a] = b;
	else
		P[b] = a;
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		P[i] = i;
	int T = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char c;
			cin >> c;
			if (c == '0') continue;
			int d = 0;
			if ('a' <= c && c <= 'z')
				d = c - 'a' + 1;
			else
				d = c - 'A' + 27;
			T += d;
			if (i == j) continue;
			E.push_back({d, i, j});
		}
	}
	sort(E.begin(), E.end());
	int cnt = 0, S = 0;
	for (auto [c, a, b] : E) {
		if (make_union(a, b)) {
			S += c;
			cnt++;
		}
	}
	cout << (N - 1 != cnt ? -1 : T - S) << '\n';
	return 0;
}