#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int A[20001], B[20001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];
		sort(A, A + N);
		sort(B, B + M, greater<int>());
		long answer = 0;
		int a = N - 1, b = 0;
		while (a >= 0 && b < M) {
			if (A[a] > B[b]) {
				a--;
				answer += M - b;
			} else {
				b++;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}