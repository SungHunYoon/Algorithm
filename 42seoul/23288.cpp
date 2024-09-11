#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using Dice = pair<vector<int>, int>;

int N, M, K;
int A[21][21];
bool V[21][21];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
Dice dice;
ii pos;

int bfs() {
	for (int i = 1; i <= N; i++)
		fill(V[i] + 1, V[i] + M + 1, false);
	queue<ii> q;
	int ret = 0;
	q.push(pos);
	V[pos.first][pos.second] = true;
	while (!q.empty()) {
		auto [cy, cx] = q.front(); q.pop();
		ret++;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (1 > ny || ny > N || 1 > nx || nx > M) continue;
			if (V[ny][nx] || A[ny][nx] != A[cy][cx]) continue;
			q.push({ny, nx});
			V[ny][nx] = true;
		}
	}
	return ret;
}

void rotateDice() {
	if (dice.second == 0) {
		if (pos.second + 1 > M) {
			dice.second = 1;
			pos.second--;
		}
		else
			pos.second++;
	} else if (dice.second == 1) {
		if (pos.second - 1 < 1) {
			dice.second = 0;
			pos.second++;
		}
		else
			pos.second--;
	} else if (dice.second == 2) {
		if (pos.first + 1 > N) {
			dice.second = 3;
			pos.first--;
		}
		else
			pos.first++;
	} else if (dice.second == 3) {
		if (pos.first - 1 < 1) {
			dice.second = 2;
			pos.first++;
		}
		else
			pos.first--;
	}
	if (dice.second == 0) {
		swap(dice.first[0], dice.first[2]);
		swap(dice.first[0], dice.first[5]);
		swap(dice.first[0], dice.first[3]);
	} else if (dice.second == 1) {
		swap(dice.first[0], dice.first[3]);
		swap(dice.first[0], dice.first[5]);
		swap(dice.first[0], dice.first[2]);
	} else if (dice.second == 2) {
		swap(dice.first[1], dice.first[0]);
		swap(dice.first[1], dice.first[4]);
		swap(dice.first[1], dice.first[5]);
	} else {
		swap(dice.first[0], dice.first[1]);
		swap(dice.first[0], dice.first[5]);
		swap(dice.first[0], dice.first[4]);
	}
}

void confirmDir() {
	if (dice.first[5] > A[pos.first][pos.second]) {
		if (dice.second == 0)
			dice.second = 2;
		else if (dice.second == 1)
			dice.second = 3;
		else if (dice.second == 2)
			dice.second = 1;
		else
			dice.second = 0;
	}
	else if (dice.first[5] < A[pos.first][pos.second]) {
		if (dice.second == 0)
			dice.second = 3;
		else if (dice.second == 1)
			dice.second = 2;
		else if (dice.second == 2)
			dice.second = 0;
		else
			dice.second = 1;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	for (int i = 1; i <= 6; i++)
		dice.first.push_back(i);
	pos = {1, 1};
	int answer = 0;
	while (K--) {
		rotateDice();
		answer += bfs() * A[pos.first][pos.second];
		confirmDir();
	}
	cout << answer << '\n';
	return 0;
}