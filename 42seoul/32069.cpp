#include <iostream>
#include <set>
#include <queue>
#include <tuple>

using namespace std;
using lll = tuple<long, long, long>;

long L, N, K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> N >> K;
	priority_queue<lll, vector<lll>, greater<lll>> pq;
	set<long> S;
	for (int i = 1; i <= N; i++) {
		long n;
		cin >> n;
		pq.push({0, n, 0});
	}
	while (!pq.empty()) {
		auto [b, n, d] = pq.top(); pq.pop();
		if (n < 0 || n > L || !S.insert(n).second)
			continue;
		cout << b++ << '\n';
		if (--K == 0)
			break;
		if (d == 0) {
			pq.push({b, n + 1, 1});
			pq.push({b, n - 1, -1});
		} else {
			pq.push({b, n + d, d});
		}
	}
	return 0;
}