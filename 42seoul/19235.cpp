#include <iostream>

using namespace std;

int N;

int G[6][4];
int B[6][4];
int dx[3][2] = {{0, 0}, {0, 0}, {0, -1}};
int dy[3][2] = {{0, 0}, {0, 1}, {0, 0}};

bool checkEmptyLine(int a[6][4], int c) {
	for (int i = 0; i < 4; i++)
		if (a[c][i]) return false;
	return true;
}

bool checkFullLine(int a[6][4], int c) {
	for (int i = 0; i < 4; i++)
		if (!a[c][i]) return false;
	return true;
}

void clearLine(int a[6][4], int c) {
	for (int i = 0; i < 4; i++)
		a[c][i] = 0;
}

void moveLine(int a[6][4], int c) {
	int orgC = c;
	while (1) {
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			if (a[orgC][i] && a[c + 1][i]) {
				flag = true;
				break;
			}
		}
		if (flag) break;
		if (c + 1 < 6) c++;
		else break;
	}
	for (int i = 0; i < 4; i++) {
		if (a[c][i]) continue;
		a[c][i] = a[orgC][i];
		a[orgC][i] = 0;
	}
}

void dropBlock(int a[6][4], int t, int x, int y, int n) {
	if (t == 1) {
		a[x][y] = n;
	} else if (t == 2) {
		a[x][y] = a[x][y + 1] = n;
	} else {
		a[x][y] = a[x + 1][y] = n;
	}
	if (!checkEmptyLine(a, 1)) moveLine(a, 1);
	if (!checkEmptyLine(a, 0)) moveLine(a, 0);
}

int calScore(int a[6][4], int *L) {
	int score = 0;
	for (int i = 2; i < 6; i++) {
		if (!checkFullLine(a, i)) continue;
		*L = i;
		score++;
		clearLine(a, i);
	}
	return score;
}

int checkType(int a[6][4], int x, int y) {
	for (int i = 2; i >= 0; i--) {
		bool flag = true;
		for (int j = 0; j < 2; j++) {
			int nx = x + dx[i][j];
			int ny = y + dy[i][j];
			if (0 > nx || nx > 6 || 0 > ny || ny > 4) {
				flag = false;
				break;
			}
			if (a[x][y] != a[nx][ny]) {
				flag = false;
				break;
			}
		}
		if (flag) return i;
	}
	return 0;
}

bool checkEmptyBlock(int a[6][4], int t, int x, int y) {
	for (int i = 0; i < 2; i++) {
		if (t == 2 && i > 0) continue;
		if (a[x + dx[t][i]][y + dy[t][i]])
			return false;
	}
	return true;
}

void moveCol(int a[6][4], int L) {
	for (int i = L; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (!a[i][j]) continue;
			int type = checkType(a, i, j);
			int k = i + 1;
			int val1 = a[i + dx[type][0]][j + dy[type][0]];
			int val2 = a[i + dx[type][1]][j + dy[type][1]];
			while (k < 6 && checkEmptyBlock(a, type, k, j))
				k++;
			a[i + dx[type][0]][j + dy[type][0]] = 0;
			a[i + dx[type][1]][j + dy[type][1]] = 0;
			a[k + dx[type][0] - 1][j + dy[type][0]] = val1;
			a[k + dx[type][1] - 1][j + dy[type][1]] = val2;
		}
	}
}

void moveArr(int a[6][4]) {
	while (!(checkEmptyLine(a, 0) && checkEmptyLine(a, 1))) {
		for (int i = 4; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				a[i + 1][j] = a[i][j];
				a[i][j] = 0;
			}
		}
	}
}

int countArr(int a[6][4]) {
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++)
			if (a[i][j]) cnt++;
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			dropBlock(G, t, 0, y, i);
			dropBlock(B, t, 0, x, i);
		} else {
			dropBlock(G, t, 0, y, i);
			t ^= 1;
			dropBlock(B, t, 0, x, i);
		}
		int gScore, bScore, gL, bL;
		gScore = calScore(G, &gL);
		bScore = calScore(B, &bL);
		while (gScore || bScore) {
			if (gScore) moveCol(G, gL);
			if (bScore) moveCol(B, bL);
			answer += gScore + bScore;
			moveArr(G);
			moveArr(B);
			gScore = calScore(G, &gL);
			bScore = calScore(B, &bL);
		}
		moveArr(G);
		moveArr(B);
	}
	cout << answer << '\n' << countArr(G) + countArr(B) << '\n';

	return 0;
}