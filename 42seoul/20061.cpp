#include <iostream>

using namespace std;

int N, X, Y, T;
int G[6][4];
int B[4][6];

void moveGreen(int x, int y, int t) {
	for (int i = 0, x = 0; i < 6; i++, x++) {
		if (t == 1) {
			if (G[x][y] == 1)
				break;
			if (x - 1 >= 0)
				G[x - 1][y] = 0;
			G[x][y] = 1;
		} else if (t == 2) {
			if (G[x][y] == 1 || G[x][y + 1] == 1)
				break;
			if (x - 1 >= 0) {
				G[x - 1][y] = 0;
				G[x - 1][y + 1] = 0;
			}
			G[x][y] = 1;
			G[x][y + 1] = 1;
		} else {
			if (G[x + 1][y] == 1)
				break;
			if (x - 1 >= 0)
				G[x - 1][y] = 0;
			G[x][y] = 1;
			G[x + 1][y] = 1;
			if (x + 1 >= 5)
				break;
		}
	}
}

int getGreenScore() {
	int ret = 0;

	for (int i = 5; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (G[i][j] == 1)
				cnt++;
		}
		if (cnt == 4) {
			ret++;
			for (int j = i - 1; j >= 0; j--) {
				for (int k = 0; k < 4; k++) {
					G[j + 1][k] = G[j][k];
				}
			}
			for (int j = 0; j < 4; j++)
				G[0][j] = 0;
			i++;
		}
	}
	return ret;
}

void moveNextGreen() {
	int move = 0;

	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (G[i][j] == 1) {
				move++;
				break;
			}
		}
	}

	for (int i = 5 - move; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			G[i + move][j] = G[i][j];
		}
	}
	for (int i = 0; i < move; i++) {
		for (int j = 0; j < 4; j++) {
			G[i][j] = 0;
		}
	}
}

void moveBlue(int x, int y, int t) {
	for (int i = 0, y = 0; i < 6; i++, y++) {
		if (t == 1) {
			if (B[x][y] == 1)
				break;
			if (y - 1 >= 0)
				B[x][y - 1] = 0;
			B[x][y] = 1;
		} else if (t == 2) {
			if (B[x][y + 1] == 1)
				break;
			if (y - 1 >= 0)
				B[x][y - 1] = 0;
			B[x][y] = 1;
			B[x][y + 1] = 1;
			if (y + 1 >= 5)
				break;
		} else {
			if (B[x][y] == 1 || B[x + 1][y] == 1)
				break;
			if (y - 1 >= 0) {
				B[x][y - 1] = 0;
				B[x + 1][y - 1] = 0;
			}
			B[x][y] = 1;
			B[x + 1][y] = 1;
		}
	}
}

int getBlueScore() {
	int ret = 0;

	for (int i = 5; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (B[j][i] == 1)
				cnt++;
		}
		if (cnt == 4) {
			ret++;
			for (int j = i - 1; j >= 0; j--) {
				for (int k = 0; k < 4; k++) {
					B[k][j + 1] = B[k][j];
				}
			}
			for (int j = 0; j < 4; j++)
				B[j][0] = 0;
			i++;
		}
	}
	return ret;
}

void moveNextBlue() {
	int move = 0;

	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (B[j][i] == 1) {
				move++;
				break;
			}
		}
	}

	for (int i = 5 - move; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			B[j][i + move] = B[j][i];
		}
	}
	for (int i = 0; i < move; i++) {
		for (int j = 0; j < 4; j++) {
			B[j][i] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int score = 0;
	while (N--) {
		cin >> T >> X >> Y;
		moveGreen(X, Y, T);
		score += getGreenScore();
		moveNextGreen();
		moveBlue(X, Y, T);
		score += getBlueScore();
		moveNextBlue();
	}
	int block = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			//cout << G[i][j] << ' ';
			if (G[i][j])
				block++;
		}
		//cout << '\n';
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			//cout << B[i][j] << ' ';
			if (B[i][j])
				block++;
		}
		//cout << '\n';
	}
	cout << score << '\n' << block << '\n';
	return 0;
}