#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, M, S, E;
vector<iii> V;
int P[100001];

int find(int idx) {
	if (idx == P[idx])
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

bool makeUnion(int a, int b) {
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

	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++) {
		int a, b, k;
		cin >> a >> b >> k;
		V.push_back({k, a, b});
	}
	for (int i = 1; i <= N; i++)
		P[i] = i;
	sort(V.begin(), V.end(), greater<iii>());
	int answer = 1e9;
	for (auto [k, a, b] : V) {
		if (makeUnion(a, b)) {
			answer = min(answer, k);
			if (find(S) == find(E))
				break;
		}
	}
	cout << (find(S) != find(E) ? 0 : answer) << '\n';
	return 0;
}