#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int>> minPQ;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		if ((minPQ.empty() && maxPQ.empty()) || maxPQ.top() >= n)
			maxPQ.push(n);
		else
			minPQ.push(n);
		while (maxPQ.size() > minPQ.size() + 1) {
			minPQ.push(maxPQ.top());
			maxPQ.pop();
		}
		while (maxPQ.size() < minPQ.size()) {
			maxPQ.push(minPQ.top());
			minPQ.pop();
		}
		cout << maxPQ.top() << '\n';
	}
	return 0;
}