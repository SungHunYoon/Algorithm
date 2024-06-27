#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
pair<int, int> S[21][21];
int A[21][21];
int P[401][4][4];
int D[401];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

pair<int, int> findShark(int idx) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (idx == A[i][j])
				return {i, j};
	return {-1, -1};
}

bool checkShark() {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != 0) {
				if (cnt == 0)
					cnt++;
				else
					return false;
			}
		}
	}
	return true;
}

bool checkEmpty(int idx, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[P[idx][D[idx]][i]];
		int ny = y + dy[P[idx][D[idx]][i]];
		
		if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
		if (S[ny][nx].first != 0) continue;
		if (A[ny][nx] == 0)
			A[ny][nx] = idx;
		else
			A[ny][nx] = min(idx, A[ny][nx]);
		A[y][x] = 0;
		D[idx] = P[idx][D[idx]][i];
		return true;
	}
	return false;
}

void movePriority(int idx, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[P[idx][D[idx]][i]];
		int ny = y + dy[P[idx][D[idx]][i]];

		if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
		if (S[ny][nx].first != idx) continue;
		if (A[ny][nx] == 0)
			A[ny][nx] = idx;
		else
			A[ny][nx] = min(idx, A[ny][nx]);
		A[y][x] = 0;
		D[idx] = P[idx][D[idx]][i];
		break;
	}
}

void moveShark() {
	for (int i = 1; i <= M; i++) {
		auto [y, x] = findShark(i);
		if (x == -1 && y == -1)
			continue;
		if (checkEmpty(i, x, y))
			continue;
		movePriority(i, x, y);
	}
}

void smellShark() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != 0) {
				S[i][j].first = A[i][j];
				S[i][j].second = K;
			}
		}
	}
}

void decreaseSmell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (S[i][j].first != 0) {
				--S[i][j].second;
				if (S[i][j].second == 0)
					S[i][j].first = 0;
			}
		}
	}
}

void printShark() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> D[i];
		D[i]--;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> P[i][j][k];
				P[i][j][k]--;
			}
		}
	}

	int i = 0;
	while (i <= 1000) {
		smellShark();
		// printShark();
		if (checkShark()) {
			cout << i << '\n';
			return 0;
		}
		moveShark();
		decreaseSmell();
		i++;
	}
	cout << "-1\n";

	return 0;
}