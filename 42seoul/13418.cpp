#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, M;
int P[1001];
vector<iii> E;

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

	cin >> N >> M;
	for (int i = 0; i < M + 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		E.push_back({c, a, b});
	}
	int minT = 0, maxT = 0;
	sort(E.begin(), E.end(), greater<iii>());
	for (int i = 1; i <= N; i++)
		P[i] = i;
	for (auto [c, a, b] : E) {
		if (make_union(a, b))
			minT += (c ? 0 : 1);
	}
	for (int i = 1; i <= N; i++)
		P[i] = i;
	sort(E.begin(), E.end());
	for (auto [c, a, b] : E) {
		if (make_union(a, b))
			maxT += (c ? 0 : 1);
	}
	cout << (maxT * maxT) - (minT * minT) << '\n';
	return 0;
}