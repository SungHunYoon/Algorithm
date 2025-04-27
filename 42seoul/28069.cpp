#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool D[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	int cnt = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int x = q.front(); q.pop();
			int nc = cnt + 1;
			int nx = x + 1;
			if (nx <= N && !D[nx]) {
				D[nx] = true;
				q.push(nx);
			}
			nx = x + x / 2;
			if (nx <= N && !D[nx]) {
				D[nx] = true;
				q.push(nx);
			}
		}
		cnt++;
		if (cnt >= K)
			break;
	}
	cout << (D[N] ? "minigimbob\n" : "water\n");
	return 0;
}