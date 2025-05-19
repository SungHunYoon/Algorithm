#include <iostream>

using namespace std;
using ii = pair<int, int>;

int N, T;
ii A[1001];
int D[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> T;
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
		total += A[i].second;
	}
	for (int i = 0; i < N; i++) {
		auto [d, m] = A[i];
		for (int j = T; j >= d; j--) {
			D[j] = max(D[j], D[j - d] + m);
		}
	}
	cout << total - D[T] << '\n';
	return 0;
}