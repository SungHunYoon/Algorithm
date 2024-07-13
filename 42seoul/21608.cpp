#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M[21][21];
int A[401];
int L[401][4];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int score[] = {0, 1, 10, 100, 1000};

void printMap() {
	cout << "=============\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << M[i][j] << ' ';
		}
		cout << '\n';
	}
}

void findSeat(int idx) {
	vector<pair<int, int>> p;
	int maxCnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (M[i][j] == 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (1 > nx || nx > N || 1 > ny || ny > N) continue;
					if (M[ny][nx] == 0) continue;
					for (int l = 0; l < 4; l++) {
						if (M[ny][nx] == L[idx][l])
							cnt++;
					}
				}
				if (maxCnt < cnt) {
					maxCnt = cnt;
					p.clear();
				}
				if (cnt == maxCnt)
					p.push_back({i, j});
			}
		}
	}
	if (p.size() > 1) {
		vector<pair<int, int>> e;
		maxCnt = 0;
		for (int i = 0; i < p.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int nx = p[i].second + dx[j];
				int ny = p[i].first + dy[j];
				if (1 > nx || nx > N || 1 > ny || ny > N) continue;
				if (M[ny][nx] != 0) continue;
				cnt++;
			}
			if (cnt > maxCnt) {
				maxCnt = cnt;
				e.clear();
			}
			if (maxCnt == cnt)
				e.push_back(p[i]);
		}
		if (e.size() > 1)
			sort(e.begin(), e.end());
		p.clear();
		p.push_back(e[0]);
	}
	M[p[0].first][p[0].second] = idx;
}

int sumAnswer() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (1 > ny || ny > N || 1 > nx || nx > N) continue;
				for (int l = 0; l < 4; l++) {
					if (M[ny][nx] == L[M[i][j]][l])
						cnt++;
				}
			}
			ret += score[cnt];
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N * N; i++) {
		cin >> A[i] >> L[A[i]][0] >> L[A[i]][1] >> L[A[i]][2] >> L[A[i]][3];
		findSeat(A[i]);
		// printMap();
	}
	cout << sumAnswer() << '\n';
	return 0;
}