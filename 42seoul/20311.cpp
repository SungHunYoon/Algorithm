#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, K;
ii A[300001];
int B[300001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		int n;
		cin >> n;
		A[i] = {n, i};
	}
	sort(A + 1, A + K + 1, greater<ii>());
	int idx = 1;
	for (int i = 1; i <= K; i++) {
		if (A[i].first * 2 - 1 > N) {
			cout << "-1\n";
			return 0;
		}
		for (int j = 0; j < A[i].first; j++) {
			B[idx] = A[i].second;
			idx += 2;
			if (idx > N) {
				idx = 2;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << B[i] << ' ';
	}
	cout << '\n';
	return 0;
}