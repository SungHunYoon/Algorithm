#include <iostream>
#include <algorithm>

using namespace std;

int N, M, R;
int A[2001], B[40001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> B[i];
	}
	sort(A + 1, A + N + 1);
	sort(B + 1, B + M + 1);
	R *= 2;
	int answer = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int w = A[j] - A[i];
			int s = 0, e = M + 1;
			while (s + 1 < e) {
				int mid = (s + e) / 2;
				if (w * B[mid] <= R) {
					s = mid;
				} else {
					e = mid;
				}
			}
			if (s != 0) answer = max(answer, w * B[s]);
		}
	}
	if (answer == -1) {
		cout << answer << '\n';
	} else {
		cout.precision(1);
		cout << fixed << (answer / 2.0) << '\n';
	}
	return 0;
}