#include <iostream>

using namespace std;

int N, X, Y;
int A[500][500];
// 5%, 10%, 10%, 2%, 7%, 7%, 2%, 1%, 1%
double p[9] = {0.05, 0.10, 0.10, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01};
// W S E N
int dx[4][10] = {
	{-2, -1, -1, 0, 0, 0, 0, 1, 1, -1},
	{0, -1, 1, -2, -1, 1, 2, -1, 1, 0},
	{2, 1, 1, 0, 0, 0, 0, -1, -1, 1},
	{0, -1, 1, -2, -1, 1, 2, -1, 1, 0},
};
int dy[4][10] = {
	{0, -1, 1, -2, -1, 1, 2, -1, 1, 0},
	{2, 1, 1, 0, 0, 0, 0, -1, -1, 1},
	{0, -1, 1, -2, -1, 1, 2, -1, 1, 0},
	{-2, -1, -1, 0, 0, 0, 0, 1, 1, -1},
};

void printMap() {
	cout << "=====================\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
}

int sumMap() {
	int ret = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ret += A[i][j];
	return ret;
}

void scatter(int dir) {
	if (dir == 0)
		X -= 1;
	else if (dir == 1)
		Y += 1;
	else if (dir == 2)
		X += 1;
	else
		Y -= 1;
	int mod = 0;
	int np;
	for (int i = 0; i < 10; i++) {
		int nx = X + dx[dir][i];
		int ny = Y + dy[dir][i];
		
		if (i < 9) {
			np = A[Y][X] * p[i];
			mod += np;
		}
		if (0 > nx || nx >= N || 0 > ny || ny >= N)
			continue;
		if (i == 9)
			A[ny][nx] += A[Y][X] - mod;
		else
			A[ny][nx] += np;
	}
	A[Y][X] = 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	int dir = 0;
	int r = 1;
	int cnt = 0;
	int sum = sumMap();
	X = N / 2, Y = N / 2;
	while (1) {
		for (int i = 0; i < r; i++) {
			if (X == 0 && Y == 0) {
				cout << sum - sumMap() << '\n';
				return 0;
			}
			scatter(dir);
			//printMap();
		}
		dir++;
		if (dir >= 4)
			dir = 0;
		cnt++;
		if (cnt >= 2) {
			cnt = 0;
			r++;
		}
	}
}
