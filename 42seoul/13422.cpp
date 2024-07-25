#include <iostream>

using namespace std;

int T, N, M, K;
int A[100001];

int checkPossible() {
	int cnt = 0;
	int start = 0;
	int end = M;
	long sum = 0;

	for (int i = start; i < end; i++)
		sum += A[i];
	if (sum < K)
		cnt++;
	if (N == M)
		return cnt;
	while (start < N - 1) {
		sum -= A[start];
		sum += A[end];
		start++;
		end++;
		if (end >= N)
			end = 0;
		if (sum < K)
			cnt++;
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << checkPossible() << '\n';
	}

	return 0;
}