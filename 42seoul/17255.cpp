#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

string N;
map<deque<char>, int> M;

bool isEqual(deque<char> &a, deque<char> &b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool isFind(deque<char> &a) {
	string S;
	for (int i = 0; i < a.size(); i++) {
		S.append(1, a[i]);
	}
	auto it = N.find(S);
	if (it == string::npos)
		return false;
	return true;
}

int dfs(deque<char> &dq) {
	if (N.size() == dq.size()) {
		for (int i = 0; i < dq.size(); i++) {
			if (N[i] != dq[i]) {
				return 0;
			}
		}
		return 1;
	}
	auto it = M.find(dq);
	if (it != M.end()) {
		return it->second;
	}
	int ret = 0;
	deque<char> frontDQ = dq;
	deque<char> backDQ = dq;
	for (int i = 0; i <= 9; i++) {
		frontDQ.push_front(i + '0');
		backDQ.push_back(i + '0');
		if (isFind(frontDQ)) {
			ret += dfs(frontDQ);
		}
		if (!isEqual(frontDQ, backDQ) && isFind(backDQ)) {
			ret += dfs(backDQ);
		}
		frontDQ.pop_front();
		backDQ.pop_back();
	}
	return M[dq] = ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		deque<char> dq;
		dq.push_back(i + '0');
		answer += dfs(dq);
	}
	cout << answer << '\n';
	return 0;
}