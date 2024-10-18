#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, M, K, X, Y;
int A[30001];
int P[30001];
int C[30001];
int D[3001];
map<int, int> m;

int find(int idx) {
	if (P[idx] == idx)
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b)
		return;
	if (a < b) {
		P[b] = a;
		C[a] += C[b];
	}
	else {
		P[a] = b;
		C[b] += C[a];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i <= N; i++) {
		P[i] = i;
		C[i] = A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		make_union(X, Y);
	}
	for (int i = 1; i <= N; i++)
		m[find(i)]++;
	for (auto [i, cnt] : m)
		for (int j = K; j >= cnt; j--)
			D[j] = max(D[j], D[j - cnt] + C[i]);
	cout << D[K - 1] << '\n';
	return 0;
}
