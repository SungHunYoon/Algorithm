#include <iostream>
#include <algorithm>

using namespace std;

int N;
string answer;

bool check(string &tmp) {
	string t;
	for (int i = (int)tmp.size() - 1; i > t.size(); i--) {
		t = tmp.substr(i);
		if (tmp.substr(i - (int)t.size(), t.size()) == t)
			return false;
	}
	return true;
}

int dfs(string str, int idx) {
	if (idx >= N) {
		answer = min(answer, str);
		return 1;
	}

	for (int i = 1; i <= 3; i++) {
		str.append(1, (char)(i + 0x30));
		if (check(str) && dfs(str, idx + 1))
			return 1;
		str.pop_back();
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	answer.assign(N, '9');
	dfs("", 0);
	cout << answer << '\n';
	return 0;
}