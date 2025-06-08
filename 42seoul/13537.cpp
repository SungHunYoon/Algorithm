#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A[100001];
vector<int> T[400004];

void init(int n, int s, int e) {
	if (s == e) {
		T[n].push_back(A[s]);
		return;
	}
	int mid = (s + e) / 2;
	init(n * 2, s, mid);
	init(n * 2 + 1, mid + 1, e);
	for (auto t : T[n * 2])
		T[n].push_back(t);
	for (auto t : T[n * 2 + 1])
		T[n].push_back(t);
	sort(T[n].begin(), T[n].end());
}

int query(int n, int s, int e, int l, int r, int v) {
	if (l > e || r < s)
		return 0;
	if (l <= s && e <= r) {
		auto it = upper_bound(T[n].begin(), T[n].end(), v);
		return ((e - s + 1) - (it - T[n].begin()));
	}
	int mid = (s + e) / 2;
	int left = query(n * 2, s, mid, l, r, v);
	int right = query(n * 2 + 1, mid + 1, e, l, r, v);
	return left + right;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	init(1, 1, N);
	cin >> M;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << query(1, 1, N, a, b, c) << '\n';
	}
	return 0;
}