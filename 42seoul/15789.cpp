#include <iostream>
#include <queue>

using namespace std;

int N, M, C, H, K;
int P[100001], D[100001], V[100001];

int find(int idx) {
	if (idx == P[idx])
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

bool make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return false;
	}
	if (a > b) {
		P[a] = P[b];
		D[b] += D[a];
	} else {
		P[b] = P[a];
		D[a] += D[b];
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		P[i] = i;
		D[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		make_union(x, y);
	}
	cin >> C >> H >> K;
	priority_queue<int> pq;
	for (int i = 1; i <= N; i++) {
		int idx = find(i);
		if (V[idx] || P[idx] == C || P[idx] == H) continue;
		V[idx] = 1;
		pq.push(D[idx]);
	}
	int i = 0, answer = 0;
	while (!pq.empty() && i < K) {
		answer += pq.top();
		pq.pop();
		i++;
	}
	cout << answer + D[C] << '\n';
	return 0;
}