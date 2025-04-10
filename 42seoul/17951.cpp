#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, K;
int A[100001];

ii countGroup(int mid) {
	int sum = 0, cnt = 0, minVal = 1e9;
	for (int i = 0; i < N; i++) {
		sum += A[i];
		if (sum >= mid) {
			minVal = min(minVal, sum);
			sum = 0;
			cnt++;
		}
	}
	if (sum >= mid) {
		cnt++;
		minVal = min(minVal, sum);
	}
	return {cnt, minVal};
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int s = 0, e = 1e9, answer = 0;
	while (s < e) {
		int mid = (s + e) / 2;
		auto [cnt, minVal] = countGroup(mid);
		if (cnt >= K) {
			s = mid + 1;
			answer = max(answer, minVal);
		} else {
			e = mid;
		}
	}
	cout << answer << '\n';
	return 0;
}