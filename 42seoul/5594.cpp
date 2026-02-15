#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> V[5001];
int inDegree[5001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		inDegree[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			cout << i << '\n';
			q.push(i);
		}
	}
	bool flag = false;
	while (!q.empty()) {
		int len = q.size();
		if (len > 1) {
			flag = true;
		}
		for (int i = 0; i < len; i++) {
			int n = q.front(); q.pop();
			for (auto v : V[n]) {
				if (--inDegree[v] == 0) {
					cout << v << '\n';
					q.push(v);
				}
			}
		}
	}
	cout << flag << '\n';

	return 0;
}