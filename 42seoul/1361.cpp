#include <iostream>
#include <algorithm>

using namespace std;

string A, B;

int getPrefix(string &s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') break;
		ret++;
	}
	return ret;
}

int getSurfix(string &s, int prefix) {
	int ret = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '*') break;
		ret++;
	}
	return ret;
}

string setPrefix(string &s, int prefix) {
	string ret;
	for (int i = 0; i < prefix; i++) {
		ret.push_back(s[i]);
	}
	return ret;
}

string setSurfix(string &s, int surfix) {
	string ret;
	for (int i = s.size() - 1; i > s.size() - surfix - 1; i--) {
		ret.push_back(s[i]);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B;
	int aPrefix = getPrefix(A);
	int aSurfix = getSurfix(A, aPrefix);
	int bPrefix = getPrefix(B);
	int bSurfix = getSurfix(B, bPrefix);

	bool isPossible = true;
	for (int i = 0; i < min(aPrefix, bPrefix); i++) {
		if (A[i] != B[i]) {
			isPossible = false;
			break;
		}
	}
	for (int i = A.size() - 1, j = B.size() - 1; i > aPrefix && j > bPrefix; i--, j--) {
		if (A[i] != B[j]) {
			isPossible = false;
			break;
		}
	}
	if (!isPossible) {
		cout << "-1\n";
	} else {
		string prefix;
		if (aPrefix > bPrefix) {
			prefix = setPrefix(A, aPrefix);
		} else {
			prefix = setPrefix(B, bPrefix);
		}
		string surfix;
		if (aSurfix > bSurfix) {
			surfix = setSurfix(A, aSurfix);
		} else {
			surfix = setSurfix(B, bSurfix);
		}
		int L = max(aPrefix + aSurfix, bPrefix + bSurfix);
		while (1) {
			int t = (int)prefix.size() + (int)surfix.size() - L;
			if (t <= 0) break;
			bool isOk = true;
			for (int i = 0; i < t; i++) {
				if (prefix[prefix.size() - t + i] != surfix[i]) {
					isOk = false;
					break;
				}
			}
			if (isOk) break;
			L++;
		}
		string answer(L, 'A');
		for (int i = 0; i < prefix.size(); i++) {
			answer[i] = prefix[i];
		}
		for (int i = 0; i < surfix.size(); i++) {
			answer[L - surfix.size() + i] = surfix[i];
		}
		cout << answer << '\n';
	}

	return 0;
}