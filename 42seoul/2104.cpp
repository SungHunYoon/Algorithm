#include <iostream>

using namespace std;

int N;
int A[100001];
long P[100001];
int T[400000];

void build(int s, int e, int n) {
	if (s == e) {
		T[n] = s;
		return;
	}
	int mid = (s + e) / 2;
	int left = n * 2;
	int right = left + 1;
	build(s, mid, left);
	build(mid + 1, e, right);
	if (A[T[left]] < A[T[right]])
		T[n] = T[left];
	else
		T[n] = T[right];
}

int query(int s, int e, int rs, int re, int n) {
	if (s > re || e < rs)
		return 0;
	if (rs <= s && e <= re)
		return T[n];
	int mid = (s + e) / 2;
	int left = query(s, mid, rs, re, n * 2);
	int right = query(mid + 1, e, rs, re, n * 2 + 1);
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
	int minIdx = query(1, N, s, e, 1);
	long ret = A[minIdx] * (P[e] - P[s] + A[s]);
	if (minIdx - 1 >= s)
		ret = max(ret, findMax(s, minIdx - 1));
	if (minIdx + 1 <= e)
		ret = max(ret, findMax(minIdx + 1, e));
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		P[i] = P[i - 1] + A[i];
	}
	build(1, N, 1);
	cout << findMax(1, N) << '\n';
	return 0;
}