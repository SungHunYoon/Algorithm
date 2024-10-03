#include <iostream>
#include <algorithm>

using namespace std;

int N;
int D[10][10];

long dfs(int prev, int idx, long num, int *cnt) {
	long ret = -1;

	if (idx <= 0) {
		(*cnt)++;
		if (*cnt == N)
			return num;
		return -1;
	}

	for (int i = 0; i < prev; i++) {
		long n = num * 10 + i;
		ret = dfs(i, idx - 1, n, cnt);
		if (ret != -1)
			return ret;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	fill(D[0], D[0] + 10, 1);
	for (int i = 1; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			int sum = 0;
			for (int k = 0; k < j; k++)
				sum += D[i - 1][k];
			D[i][j] = sum;
		}
	}
	int num = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			num += D[i][j];
			if (num >= N) {
				int cnt = num - D[i][j];
				cout << dfs(j, i, j, &cnt) << '\n';
				return 0;
			}
		}
	}
	cout << "-1\n";
	return 0;
}