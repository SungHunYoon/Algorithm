#include <iostream>

using namespace std;

int N, M;
int A[100001];
int T[2][400000];

int tree_init(int idx, int s, int e, int n) {
	if (s == e)
		return T[idx][n] = A[s];
	int mid = (s + e) / 2;
	if (idx == 0)
		T[idx][n] = max(tree_init(idx, s, mid, n * 2), tree_init(idx, mid + 1, e, n * 2 + 1));
	else
		T[idx][n] = min(tree_init(idx, s, mid, n * 2), tree_init(idx, mid + 1, e, n * 2 + 1));
	return T[idx][n];
}

int tree_search(int idx, int s, int e, int rs, int re, int n) {
	if (e < rs || s > re) {
		if (idx == 0)
			return 0;
		else
			return 1e9;
	}
	if (rs <= s && e <= re)
		return T[idx][n];
	int mid = (s + e) / 2;
	int ret;
	if (idx == 0)
		ret = max(tree_search(idx, s, mid, rs, re, n * 2), tree_search(idx, mid + 1, e, rs, re, n * 2 + 1));
	else
		ret = min(tree_search(idx, s, mid, rs, re, n * 2), tree_search(idx, mid + 1, e, rs, re, n * 2 + 1));
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	tree_init(0, 1, N, 1);
	tree_init(1, 1, N, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << tree_search(1, 1, N, a, b, 1) << ' ';
		cout << tree_search(0, 1, N, a, b, 1) << '\n';
	}
	return 0;
}