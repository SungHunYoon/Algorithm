#include <iostream>

using namespace std;

long A[8][8];
long B[8][8];
char D;
char T[] = "ULDR";

void print() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

void move() {
	for (int i = 0; i < 8; i++) {
		int bIdx = 0;
		for (int j = 0; j < 8; j++) {
			if (A[j][i]) {
				B[bIdx][i] = A[j][i];
				bIdx++;
			}
			A[j][i] = 0;
		}
	}
	for (int i = 0; i < 8; i++) {
		int aIdx = 0;
		for (int j = 0; j < 8; j++, aIdx++) {
			if (j + 1 < 8 && B[j][i] == B[j + 1][i]) {
				A[aIdx][i] = B[j][i] * 2;
				j++;
			} else {
				A[aIdx][i] = B[j][i];
			}
		}
	}
}

void rotate() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			B[j][8 - i - 1] = A[i][j];
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			A[i][j] = B[i][j];
			B[i][j] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> A[i][j];
		}
	}
	cin >> D;
	for (int i = 0; i < 4; i++) {
		if (T[i] == D) {
			int j = 0;
			while (j < i) {
				rotate();
				j++;
			}
			move();
			while (j != 0) {
				rotate();
				j = (j + 1) % 4;
			}
		}
	}
	print();
	return 0;
}