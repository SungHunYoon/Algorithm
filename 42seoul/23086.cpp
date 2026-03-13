#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, K;
set<int> S[100001];

bool bfs(vector<int> &visit, int idx, int val) {
	queue<ii> q;
	visit[idx] = val;
	q.push({idx, val});
	while (!q.empty()) {
		auto [n, v] = q.front(); q.pop();
		for (auto s : S[n]) {
			if (visit[s]) {
				if (visit[s] == v) return false;
				else continue;
			}
			visit[s] = (v == 1 ? 2 : 1);
			q.push({s, visit[s]});
		}
	}
	return true;
}

ii cntRedBlue(vector<int> visit) {
	int rCount = 0, bCount = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) {
			rCount++;
		} else if (visit[i] == 2) {
			bCount++;
		}
	}
	return {rCount, bCount};
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	vector<ii> A(M + 1);
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		A[i] = {a, b};
		S[a].insert(b);
		S[b].insert(a);
	}
	vector<int> R(K + 1);
	for (int i = 1; i <= K; i++) {
		int a;
		cin >> a;
		R[i] = a;
	}
	int s = -1, e = K + 1;
	vector<int> visit(N + 1);
	int answer = -1, rCount = 0, bCount = 0;
	while (s + 1 < e) {
		int mid = (s + e) / 2;
		for (int i = max(s, 1); i <= mid; i++) {
			S[A[R[i]].first].erase(A[R[i]].second);
			S[A[R[i]].second].erase(A[R[i]].first);
		}
		for (int i = mid + 1; i <= min(e, K - 1); i++) {
			S[A[R[i]].first].insert(A[R[i]].second);
			S[A[R[i]].second].insert(A[R[i]].first);
		}
		fill(visit.begin(), visit.end(), 0);
		bool isValid;
		for (int i = 1; i <= N; i++) {
			if (visit[i]) continue;
			isValid = bfs(visit, i, 1);
			if (!isValid) break;
		}
		if (isValid) {
			e = mid;
			ii cnt = cntRedBlue(visit);
			answer = mid;
			rCount = cnt.first;
			bCount = cnt.second;
		} else {
			s = mid;
		}
	}
	cout << answer << '\n';
	if (answer != -1) cout << min(rCount, bCount) << " " << max(rCount, bCount) << '\n';

	return 0;
}