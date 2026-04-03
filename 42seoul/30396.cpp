#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int input() {
	int ret = 0;
	for (int i = 0; i < 16; i++) {
		char c;
		cin >> c;
		ret |= ((c - '0') << i);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int start = input();
	int end = input();
	vector<int> visit((1 << 16) + 1, 1e9);
	queue<int> q;
	visit[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		for (int mask = 1, idx = 0; mask < 1 << 16; mask <<= 1, idx++) {
			if (s & mask) {
				int x = idx / 4;
				int y = idx % 4;
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (0 > nx || nx >= 4 || 0 > ny || ny >= 4) continue;
					int next = (1 << (nx * 4 + ny));
					if (s & next) continue;
					next |= s;
					next &= ~(s & mask);
					if (visit[next] != 1e9) continue;
					visit[next] = visit[s] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << visit[end] << '\n';
	return 0;
}