#include <iostream>

using namespace std;

char A[5][9];
int T[12];
bool V[13];

bool checkStar(void) {
	int a = T[0] + T[2] + T[5] + T[7];
	int b = T[0] + T[3] + T[6] + T[10];
	int c = T[1] + T[2] + T[3] + T[4];
	int d = T[7] + T[8] + T[9] + T[10];
	int e = T[1] + T[5] + T[8] + T[11];
	int f = T[4] + T[6] + T[9] + T[11];
	return (a == b && b == c && c == d && d == e && e == f && f == 26);
}

bool dfs(int idx) {
	if (idx >= 12)
		return checkStar();
	if (T[idx] != -1)
		return dfs(idx + 1);
	for (int i = 1; i <= 12; i++) {
		if (V[i]) continue;
		V[i] = true;
		T[idx] = i;
		if (dfs(idx + 1))
			return true;
		T[idx] = -1;
		V[i] = false;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int idx = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'x')
				T[idx++] = -1;
			else if (A[i][j] != '.') {
				int v = A[i][j] - 'A' + 1;
				T[idx++] = v;
				V[v] = true;
			}
		}
	}
	dfs(0);
	idx = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (A[i][j] != '.') cout << (char)(T[idx++] + 'A' - 1);
			else cout << A[i][j];
		}
		cout << '\n';
	}
	return 0;
}