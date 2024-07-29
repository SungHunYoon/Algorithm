#include <iostream>

using namespace std;

int N, M;
int A[100001];

bool isPossible(long mid) {
	long cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += mid / A[i];
		if (cnt >= M)
			break;
	}
	if (cnt < M)
		return false;
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	long start = 0, end = 1e18;
	long answer = 0;
	while (start <= end) {
		long mid = (start + end) / 2;
		if (isPossible(mid)) {
			answer = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	cout << answer << '\n';
	return 0;
}