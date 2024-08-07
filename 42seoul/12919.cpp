#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

string S, T;

int dfs(string str) {
	if (str.size() <= S.size()) {
		if (str == S)
			return 1;
		return 0;
	}
	
	string t;
	if (str.back() == 'A') {
		t = str;
		t.pop_back();
		if (dfs(t))
			return 1;
	}

	if (str.front() == 'B') {
		t = str;
		reverse(t.begin(), t.end());
		t.pop_back();
		if (dfs(t))
			return 1;
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> T;
	cout << dfs(T) << '\n';
	return 0;
}