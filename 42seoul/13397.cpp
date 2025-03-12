#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[5001];

int calPartialCnt(int mid) {
	int ret = 0;
	int maxV = 0, minV = 1e9;
	for (int i = 1; i <= N; i++) {
		maxV = max(maxV, A[i]);
		minV = min(minV, A[i]);
		if (maxV - minV >= mid) {
			ret++;
			maxV = minV = A[i];
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	int answer = 0;
	int s = 0, e = 10001;
	while (s < e) {
		int mid = (s + e) / 2;
		if (calPartialCnt(mid) >= M) {
			answer = mid;
			s = mid + 1;
		} else {
			e = mid;
		}
	}
	cout << answer << '\n';
	return 0;
}