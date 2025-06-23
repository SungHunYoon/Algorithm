#include <iostream>

using namespace std;

int N, X;
string S = "helloworld";
int T[26];
int num[10];

bool dfs(int idx) {
	if (idx >= S.size()) {
		int a = 0, b = 0;
		for (int i = 0; i < S.size() / 2; i++) {
			a += T[S[i] - 'a'];
			b += T[S[i + 5] - 'a'];
			if (i + 1 < S.size() / 2) {
				a *= 10;
				b *= 10;
			}
		}
		X = a + b;
		if (X == N)
			return true;
		return false;
	}
	if (T[S[idx] - 'a']) {
		if (dfs(idx + 1))
			return true;
		return false;
	}
	for (int i = 0; i <= 9; i++) {
		if (i == 0 && (S[idx] == 'h' || S[idx] == 'w')) continue;
		if (num[i]) continue;
		T[S[idx] - 'a'] = i;
		num[i] = 1;
		if (dfs(idx + 1))
			return true;
		num[i] = 0;
		T[S[idx] - 'a'] = 0;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	if (!dfs(0)) {
		cout << "No Answer\n";
	} else {
		cout << "  ";
		for (int i = 0; i < 5; i++)
			cout << T[S[i] - 'a'];
		cout << '\n';
		cout << "+ ";
		for (int i = 5; i < 10; i++)
			cout << T[S[i] - 'a'];
		cout << '\n';
		cout << "-------\n";
		if (X / 100000 > 0)
			cout << " ";
		else
			cout << "  ";
		cout << X << '\n';
	}

	return 0;
}