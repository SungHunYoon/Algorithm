#include <iostream>

using namespace std;

int N;
int A[501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int answer = 1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int d = A[j] - A[i];
			if (i == j)
				d = 0;
			else
				d /= abs(j - i);
			int cnt = 0, prev = A[i];
			for (int k = i - 1; k >= 1; k--) {
				if (prev - A[k] != d) {
					prev = prev + d;
					cnt++;
				} else {
					prev = A[k];
				}
			}
			prev = A[i];
			for (int k = i + 1; k <= N; k++) {
				if (A[k] - prev != d) {
					prev = prev + d;
					cnt++;
				} else {
					prev = A[k];
				}
			}
			answer = min(answer, cnt);
		}
	}
	cout << answer << '\n';
	return 0;
}