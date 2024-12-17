#include <iostream>
#include <algorithm>

using namespace std;

string S;
char A[101];

void dfs(int idx) {
	auto it = min_element(S.begin() + idx, S.end());
	while (*it != 'a') {
		int d = it - S.begin();
		A[d] = *it;
		for (int i = 0; i < S.size(); i++)
			if (A[i]) cout << A[i];
		cout << '\n';
		*it = 'a';
		dfs(d);
		it = min_element(S.begin() + idx, S.end());
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	dfs(0);
	return 0;
}