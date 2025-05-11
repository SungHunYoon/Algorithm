#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, A, B;
bool P[1000001];

int bfs() {
	int cnt = 0;
	vector<bool> V(1000001);
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int v = q.front(); q.pop();
			if (A <= v && v <= B && !P[v])
				return cnt;
			int nv = v / 2;
			if (nv > 0 && !V[nv]) {
				V[nv] = true;
				q.push(nv);
			}
			nv = v / 3;
			if (nv > 0 && !V[nv]) {
				V[nv] = true;
				q.push(nv);
			}
			nv = v - 1;
			if (nv > 0 && !V[nv]) {
				V[nv] = true;
				q.push(nv);
			}
			nv = v + 1;
			if (nv <= 1000000 && !V[nv]) {
				V[nv] = true;
				q.push(nv);
			}
		}
		cnt++;
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	P[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (P[i]) continue;
		for (int j = i + i; j <= 1000000; j += i)
			P[j] = true;
	}
	cin >> T;
	while (T--) {
		cin >> N >> A >> B;
		cout << bfs() << '\n';
	}

	return 0;
}