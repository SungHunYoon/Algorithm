#include <iostream>

using namespace std;

int N, M;
int A[100001], B[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> B[i];
	}
	int frontRowIdx = 1, backRowIdx = N, columnIdx = 1;
	for (int i = 1; i <= N; i++) {
		if (A[frontRowIdx] < A[i]) {
			frontRowIdx = i;
		}
	}
	for (int i = N; i >= 1; i--) {
		if (A[backRowIdx] < A[i]) {
			backRowIdx = i;
		}
	}
	for (int i = 1; i <= M; i++) {
		if (B[columnIdx] < B[i]) {
			columnIdx = i;
		}
	}
	long long answer = 0;
	for (int i = 1; i < frontRowIdx; i++) {
		answer += A[i] * (long long)1e9 + B[1];
	}
	for (int i = 1; i <= columnIdx; i++) {
		answer += A[frontRowIdx] * (long long)1e9 + B[i];
	}
	for (int i = frontRowIdx + 1; i <= backRowIdx; i++) {
		answer += A[i] * (long long)1e9 + B[columnIdx];
	}
	for (int i = columnIdx + 1; i <= M; i++) {
		answer += A[backRowIdx] * (long long)1e9 + B[i];
	}
	for (int i = backRowIdx + 1; i <= N; i++) {
		answer += A[i] * (long long)1e9 + B[M];
	}
	cout << answer << '\n';
	return 0;
}