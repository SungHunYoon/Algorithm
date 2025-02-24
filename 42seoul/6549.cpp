#include <iostream>

using namespace std;

int N;
int A[100001];
int T[400000];

int tree_init(int s, int e, int n) {
	if (s == e)
		return T[n] = s;
	int mid = (s + e) / 2;
	int left = tree_init(s, mid, n * 2);
	int right = tree_init(mid + 1, e, n * 2 + 1);
	if (A[left] < A[right])
		T[n] = left;
	else
		T[n] = right;
	return T[n];
}

int tree_search(int s, int e, int rs, int re, int n) {
	if (s > re || e < rs)
		return 0;
	if (rs <= s && e <= re)
		return T[n];
	int mid = (s + e) / 2;
	int left = tree_search(s, mid, rs, re, n * 2);
	int right = tree_search(mid + 1, e, rs, re, n * 2 + 1);
	if (left == 0)
		return right;
	if (right == 0)
		return left;
	if (A[left] < A[right])
		return left;
	else
		return right;
}

long findMax(int s, int e) {
	int minIdx = tree_search(1, N, s, e, 1);
	long ret = (long)A[minIdx] * (e - s + 1);
	if (s <= minIdx - 1)
		ret = max(ret, findMax(s, minIdx - 1));
	if (minIdx + 1 <= e)
		ret = max(ret, findMax(minIdx + 1, e));
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> N) {
		if (N == 0)
			break;
		for (int i = 1; i <= N; i++)
			cin >> A[i];
		for (int i = 1; i <= 4 * N; i++)
			T[i] = 0;
		tree_init(1, N, 1);
		cout << findMax(1, N) << '\n';
	}
	return 0;
}