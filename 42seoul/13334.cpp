#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, D;
vector<ii> A;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		A.push_back({b, a});
	}
	cin >> D;
	sort(A.begin(), A.end());
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < A.size(); i++) {
		auto [e, s] = A[i];
		if (e - s > D) continue;
		while (!pq.empty() && pq.top() + D < e)
			pq.pop();
		pq.push(s);
		answer = max(answer, (int)pq.size());
	}
	cout << answer << '\n';
	return 0;
}