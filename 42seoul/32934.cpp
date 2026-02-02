#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
vector<int> V[200001];
int D[200001], C[200001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	int leafCnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!(V[i].size() == 1 || V[i].size() == 3)) {
			cout << "-1\n";
			return 0;
		}
		D[i] = 1e9;
		if (V[i].size() == 1) {
			pq.push({D[i] = 0, i});
			C[i] = 1;
			leafCnt++;
		}
	}
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto nN : V[n]) {
			if (d + 1 > D[nN]) continue;
			C[nN] += C[n];
			if (d + 1 == D[nN]) continue;
			pq.push({D[nN] = d + 1, nN});
		}
	}
	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		if (C[i] == leafCnt && V[i].size() == 3) {
			answer.push_back(i);
		}
	}
	if (answer.size()) {
		cout << answer.size() << '\n';
		for (auto a : answer) {
			cout << a << ' ';
		}
		cout << '\n';
	} else {
		cout << "-1\n";
	}
	return 0;
}