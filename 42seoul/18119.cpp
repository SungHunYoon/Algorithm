#include <iostream>

using namespace std;

int N, M;
bool T[10001][26], C[10001][26];

bool isSame(int n) {
	for (int i = 0; i < 26; i++) {
		if (C[n][i] != T[n][i])
			return false;
	}
	return true;
}

int cntDiff(int n) {
	int ret = 0;
	for (int i = 0; i < 26; i++) {
		if (C[n][i] != T[n][i])
			ret++;
	}
	return ret;
}

int findVoca(char c) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (!T[i][c - 'a']) continue;
		C[i][c - 'a'] = !C[i][c - 'a'];
		if (C[i][c - 'a']) {
			if (isSame(i))
				ret++;
		} else {
			if (cntDiff(i) == 1)
				ret++;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (auto c : s) {
			T[i][c - 'a'] = true;
			C[i][c - 'a'] = true;
		}
	}
	int cnt = N;
	for (int i = 0; i < M; i++) {
		int n;
		char c;
		cin >> n >> c;
		int ret = findVoca(c);
		if (n == 1)
			cnt -= ret;
		else
			cnt += ret;
		cout << cnt << '\n';
	}
	return 0;
}