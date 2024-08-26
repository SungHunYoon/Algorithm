#include <iostream>

using namespace std;

int N;
char A[2187][2187];

void printStar(int n, int x, int y) {
	int div = n / 3;
	for (int i = y; i < y + n; i++) {
		if (div + y <= i && i < div * 2 + y) {
			int j = x;
			for (; j < x + div; j++)
				A[i][j] = '*';
			for (; j < x + div + div; j++)
				A[i][j] = ' ';
			for (; j < x + n; j++)
				A[i][j] = '*';
		} else {
			for (int j = x; j < x + n; j++)
				A[i][j] = '*';
		}
	}
}

void recursive(int n, int x, int y) {
	if (n < 3)
		return;
	printStar(n, x, y);
	int div = n / 3;
	for (int i = y; i < y + n; i += div) {
		for (int j = x; j < x + n; j += div) {
			if (A[i][j] == '*')
				recursive(div, j, i);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	recursive(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << A[i][j];
		cout << '\n';
	}

	return 0;
}