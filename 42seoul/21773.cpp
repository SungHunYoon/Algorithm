#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using iii = tuple<int, int, int>;

int T, N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T >> N;
	priority_queue<iii> pq;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({c, -a, b});
	}
	while (T-- && !pq.empty()) {
		auto [p, id, t] = pq.top(); pq.pop();
		cout << -id << '\n';
		p--;
		t--;
		if (t <= 0) continue;
		pq.push({p, id, t});
	}
	return 0;
}