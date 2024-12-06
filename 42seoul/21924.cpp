#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, M;
vector<iii> V;
int P[100001];

int find(int idx) {
	if (idx == P[idx])
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a > b)
		P[a] = b;
	else
		P[b] = a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		P[i] = i;
	long total = 0;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V.push_back({c, a, b});
		total += c;
	}
	sort(V.begin(), V.end());
	long cost = 0;
	int cnt = 0;
	for (auto [c, a, b] : V) {
		if (find(a) == find(b)) continue;
		make_union(a, b);
		cnt++;
		cost += c;
	}
	if (cnt == N - 1) cout << total - cost << '\n';
	else cout << "-1\n";
	return 0;
}