#include <iostream>
#include <algorithm>

using namespace std;

string S;

bool checkGameover(string &s) {
	char a, b, c;
	for (int i = 0; i < 3; i++) {
		a = s[i * 3];
		b = s[i * 3 + 1];
		c = s[i * 3 + 2];
		if ((a == 'X' && b == 'X' && c == 'X') || 
			(a == 'O' && b == 'O' && c == 'O'))
			return true;
		a = s[i];
		b = s[i + 3];
		c = s[i + 6];
		if ((a == 'X' && b == 'X' && c == 'X') || 
			(a == 'O' && b == 'O' && c == 'O'))
			return true;
	}
	if ((s[0] == 'X' && s[4] == 'X' && s[8] == 'X') || 
		(s[0] == 'O' && s[4] == 'O' && s[8] == 'O') ||
		(s[2] == 'X' && s[4] == 'X' && s[6] == 'X') ||
		(s[2] == 'O' && s[4] == 'O' && s[6] == 'O'))
			return true;
	return false;
}

int dfs(string &s, int idx) {
	if (idx >= 9 || checkGameover(s)) {
		if (s == S)
			return 1;
		return 0;
	}
	for (int i = 0; i < 9; i++) {
		if (s[i] == '.') {
			if (idx % 2)
				s[i] = 'O';
			else
				s[i] = 'X';
			if (dfs(s, idx + 1))
				return 1;
			s[i] = '.';
		}
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> S) {
		if (S == "end")
			break;
		int cnt1 = count(S.begin(), S.end(), 'X');
		int cnt2 = count(S.begin(), S.end(), 'O');
		if (!(cnt1 == cnt2 || cnt1 - 1 == cnt2)) {
			cout << "invalid\n";
			continue;
		}
		string s = ".........";
		cout << (dfs(s, 0) ? "valid" : "invalid") << '\n';
	}
	return 0;
}