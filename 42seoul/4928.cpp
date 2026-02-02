#include <iostream>

using namespace std;

string S;

string dfs(int &idx) {
	string ret;

	while (idx < S.size()) {
		if (isalpha(S[idx])) {
			ret += S[idx];
			idx++;
		} else if (isdigit(S[idx])) {
			int num = atoi(&S[idx]);
			string newS;
			for (int j = 0; j < num; j++) {
				newS += ret;
			}
			ret = newS;
			if (num == 0) {
				idx++;
			} else {
				while (num > 0) {
					num /= 10;
					idx++;
				}
			}
		} else if (S[idx] == '(') {
			ret += dfs(++idx);
		} else if (S[idx] == ')') {
			idx++;
			break;
		} else {
			break;
		}
	}

	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (getline(cin, S)) {
		string trim;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == ' ') continue;
			trim.push_back(S[i]);
		}
		S = trim;
		if (S[0] == '$') {
			break;
		}
		int idx = 0;
		cout << dfs(idx) << '\n';
	}

	return 0;
}