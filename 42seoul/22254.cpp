#include <iostream>
#include <queue>

using namespace std;

int N, K;
int A[100001];

bool isPossible(int mid) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (pq.size() < mid) {
			pq.push(A[i]);
		} else {
			int t = pq.top(); pq.pop();
			t += A[i];
			if (t > K) return false;
			pq.push(t);
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int s = 1, e = 1e9 + 1;
	while (s < e) {
		int mid = (s + e) / 2;
		if (isPossible(mid)) {
			e = mid;
		} else {
			s = mid + 1;
		}
	}
	cout << e << '\n';
	return 0;
}