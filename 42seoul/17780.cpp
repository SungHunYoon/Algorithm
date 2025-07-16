#include <iostream>
#include <deque>

using namespace std;

class Knight {
	private:
		int idx, x, y, d;

	public:
		int getIdx() {
			return idx;
		}

		int getX() {
			return x;
		}

		int getY() {
			return y;
		}

		int getD() {
			return d;
		}

		void setD(int d) {
			this->d = d;
		}

		void setX(int x) {
			this->x = x;
		}

		void setY(int y) {
			this->y = y;
		}

		Knight(int idx, int x, int y, int d) {
			this->idx = idx;
			this->x = x;
			this->y = y;
			this->d = d;
		}
};

int N, K;
int A[13][13];
deque<Knight> knight;
deque<int> B[13][13];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void moveKnight(int idx) {
	int x = knight[idx].getX();
	int y = knight[idx].getY();
	int d = knight[idx].getD();
	if (B[x][y].front() != idx) {
		return;
	}
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (1 > nx || nx > N || 1 > ny || ny > N || A[nx][ny] == 2) {
		knight[idx].setD(d ^ 1);
		d = knight[idx].getD();
		nx = x + dx[d];
		ny = y + dy[d];
		if (1 > nx || nx > N || 1 > ny || ny > N) {
			return;
		}
	}
	if (A[nx][ny] == 0) {
		while (!B[x][y].empty()) {
			knight[B[x][y].front()].setX(nx);
			knight[B[x][y].front()].setY(ny);
			B[nx][ny].push_back(B[x][y].front());
			B[x][y].pop_front();
		}
	} else if (A[nx][ny] == 1) {
		while (!B[x][y].empty()) {
			knight[B[x][y].back()].setX(nx);
			knight[B[x][y].back()].setY(ny);
			B[nx][ny].push_back(B[x][y].back());
			B[x][y].pop_back();
		}
	}
}

bool checkMap(void) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (B[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		knight.push_back(Knight(i, x, y, d - 1));
		B[x][y].push_back(i);
	}
	int answer = 1;
	while (answer < 1001) {
		for (int i = 0; i < K; i++) {
			moveKnight(i);
		}
		if (checkMap()) {
			break;
		}
		answer++;
	}
	cout << (answer <= 1000 ? answer : -1) << '\n';
	return 0;
}