#include <iostream>
#include <algorithm>

using namespace std;

int K;
int A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	int answer = 0;
	for (int i = 1; i <= K; i++) {
		cin >> A[i];
		answer += A[i] / K;
		A[i] %= K;
	}
	sort(A + 1, A + K + 1);
	int idx = 1, diff = 2e9;
	while (1) {
		auto it = upper_bound(A + idx, A + K + 1, A[idx]);
		if (it == A + K + 1) {
			diff = min(diff, A[idx]);
			break;
		}
		diff = min(diff, (int)(A[idx] + ((A + K + 1) - it)));
		idx = it - A;
	}
	cout << answer + diff << '\n';
	return 0;
}