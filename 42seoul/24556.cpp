#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int A[1001];
vector<int> V[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	vector<int> inDegree(1001);
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		inDegree[a] = 1;
		V[b].push_back(a);
	}
	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] != 0) continue;
		for (int j = i + 1; j <= N; j++) {
			if (inDegree[j] != 0) continue;
			vector<int> tempInDegree = inDegree;
			queue<int> q;
			q.push(i);
			q.push(j);
			int value = 0;
			while (!q.empty()) {
				int n = q.front(); q.pop();
				value += A[n];
				for (auto v : V[n]) {
					if (--tempInDegree[v] == 0) {
						q.push(v);
					}
				}
			}
			answer.push_back(value);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer[0] << '\n';
	return 0;
}