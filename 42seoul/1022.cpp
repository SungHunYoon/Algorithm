#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int R1, R2, C1, C2;
int A[51][5];

int calCoordinate(int x, int y) {
	int rc = abs(y) >= abs(x) ? abs(y) : abs(x);
	int num = 1;
	for (int i = 1; i <= rc; i++)
		num += i * 8;
	int r = rc * 2 + 1;
	int c = rc * 2 + 1;
	for (int i = c / 2; i > -(c / 2); i--) {
		if (r / 2 == y && i == x)
			return num;
		num--;
	}
	for (int i = r / 2; i > -(r / 2); i--) {
		if (i == y && -(c / 2) == x)
			return num;
		num--;
	}
	for (int i = -(c / 2); i < c / 2; i++) {
		if (-(r / 2) == y && i == x)
			return num;
		num--;
	}
	for (int i = -(r / 2); i < r / 2; i++) {
		if (i == y && c / 2 == x)
			return num;
		num--;
	}
	return 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R1 >> C1 >> R2 >> C2;
	int maxDigit = 1;
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			A[i - R1][j - C1] = calCoordinate(j, i);
			int digit = 1;
			while (A[i - R1][j - C1] / int(pow(10, digit)) != 0)
				digit += 1;
			maxDigit = max(maxDigit, digit);
		}
	}
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++)
			cout << setw(maxDigit) << A[i - R1][j - C1] << ' ';
		cout << '\n';
	}
	return 0;
}