#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
int A[200001], B[200001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	priority_queue<ii> pq;
	for (int i = 0; i < M; i++) {
		pq.push({B[i], A[i]});
	}
	int answer = 0;
	N *= 24;
	while (N > 0 && !pq.empty()) {
		auto [b, a] = pq.top(); pq.pop();
		int s = 0, e = N + 1;
		while (s + 1 < e) {
			int mid = (s + e) / 2;
			if (100 < mid * b + a) {
				e = mid;
			} else {
				s = mid;
			}
		}
		a = s * b + a;
		b = 100 - a;
		N -= s;
		if (a < 100)
			pq.push({b, a});
		else
			answer += a;
	}
	while (!pq.empty()) {
		auto [b, a] = pq.top(); pq.pop();
		answer += a;
	}
	cout << answer << '\n';
	return 0;
}