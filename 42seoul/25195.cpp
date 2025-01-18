#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ib = pair<int, bool>;

int N, M, S;
vector<int> V[100001];
bool A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		V[u].push_back(v);
	}
	cin >> S;
	for (int i = 0; i < S; i++) {
		int s;
		cin >> s;
		A[s] = true;
	}
	string answer = "Yes";
	queue<ib> q;
	q.push({1, 0});
	while (!q.empty()) {
		auto [n, c] = q.front(); q.pop();
		if (A[n]) c = true;
		if (V[n].empty() && !c) {
			answer[0] = 'y';
			break;
		}
		for (auto v : V[n])
			q.push({v, c});
	}
	cout << answer << '\n';
	return 0;
}