#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
long A[200001];

int countWifi(long mid) {
	int cnt = 1;
	long dis = 0;
	for (int i = 1; i < N; i++) {
		dis += A[i] - A[i - 1];
		if (dis >= mid) {
			cnt++;
			dis = 0;
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	long start = 1, end = 1e9 + 1;
	while (start < end) {
		long mid = (start + end) / 2;
		int cnt = countWifi(mid);
		if (C > cnt)
			end = mid;
		else
			start = mid + 1;
	}
	cout << start - 1 << '\n';
	return 0;
}