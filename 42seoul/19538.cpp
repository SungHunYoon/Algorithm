#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> V[200001];
int A[200001], D[200001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		while (cin >> n) {
			if (n == 0)
				break;
			V[i].push_back(n);
		}
		A[i] = -1;
	}
	queue<int> q;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int m;
		cin >> m;
		q.push(m);
	}
	int t = 0;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int n = q.front(); q.pop();
			if (A[n] != -1) continue;
			A[n] = t;
			for (auto nN : V[n]) {
				if (A[nN] != -1) continue;
				if (++D[nN] < (V[nN].size() + 1) / 2) continue;
				q.push(nN);
			}
		}
		t++;
	}
	for (int i = 1; i <= N; i++)
		cout << A[i] << ' ';
	cout << '\n';
	return 0;
}