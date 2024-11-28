#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, M, K, U, V, W;
int P[1001];
int A[1001];
vector<iii> E;

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
	for (int i = 0; i < K; i++) {
		if (A[i] == a) {
			P[b] = a;
			return;
		} else if (A[i] == b) {
			P[a] = b;
			return;
		}
	}
	if (a > b)
		P[a] = b;
	else
		P[b] = a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		P[i] = i;
	for (int i = 0; i < K; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++) {
		cin >> U >> V >> W;
		E.push_back({W, U, V});
	}
	sort(E.begin(), E.end());
	int cnt = 0, answer = 0;
	for (auto [w, u, v] : E) {
		if (find(u) == find(v)) continue;
		bool uF = false, vF = false;
		for (int i = 0; i < K; i++) {
			if (A[i] == find(u))
				uF = true;
			if (A[i] == find(v))
				vF = true;
		}
		if (uF && vF) continue;
		make_union(u, v);
		cnt++;
		answer += w;
		if (cnt == N - 1) break;
	}
	cout << answer << '\n';
	return 0;
}