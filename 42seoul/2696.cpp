#include <iostream>
#include <queue>

using namespace std;

int T, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> M;
		priority_queue<int> maxPQ;
		priority_queue<int, vector<int>, greater<int>> minPQ;
		vector<int> answer;
		for (int i = 1; i <= M; i++) {
			int n;
			cin >> n;
			if (maxPQ.empty() || maxPQ.top() > n)
				maxPQ.push(n);
			else
				minPQ.push(n);
			while (maxPQ.size() > minPQ.size() + 1) {
				minPQ.push(maxPQ.top());
				maxPQ.pop();
			}
			while (maxPQ.size() < minPQ.size() + 1) {
				maxPQ.push(minPQ.top());
				minPQ.pop();
			}
			if (i % 2)
				answer.push_back(maxPQ.top());
		}
		cout << answer.size() << '\n';
		for (int i = 1; i <= answer.size(); i++)
			cout << answer[i - 1] << (i % 10 == 0 ? '\n' : ' ');
		cout << '\n';
	}

	return 0;
}