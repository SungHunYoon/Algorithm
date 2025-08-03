#include <iostream>
#include <queue>

using namespace std;

int N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	priority_queue<int> pq;
	long sum = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pq.push(x);
		sum += x;
		while (sum >= M) {
			sum -= pq.top() * 2;
			pq.pop();
		}
	}
	cout << N - pq.size() << '\n';
	return 0;
}