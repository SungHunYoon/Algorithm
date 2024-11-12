#include <iostream>
#include <vector>

using namespace std;

int T, N;
char c[] = {' ', '+', '-'};

void dfs(string &s, vector<int> &v, int idx) {
	if (idx > N) {
		int cal = 0;
		for (int i = 0; i < v.size(); i++)
			cal += v[i];
		if (cal == 0)
			cout << s << '\n';
		return;
	}
	for (int i = 0; i < 3; i++) {
		s.push_back(c[i]);
		s.push_back(idx + '0');
		if (i == 0) {
			int val = v.back() * 10; v.pop_back();
			v.push_back(val > 0 ? val + idx : val - idx);
			dfs(s, v, idx + 1);
			v.pop_back();
			v.push_back(val / 10);
		}
		else if (i == 1) {
			v.push_back(idx);
			dfs(s, v, idx + 1);
			v.pop_back();
		} else {
			v.push_back(-idx);
			dfs(s, v, idx + 1);
			v.pop_back();
		}

		s.pop_back();
		s.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		string s = "1";
		vector<int> v;
		v.push_back(1);
		dfs(s, v, 2);
		cout << '\n';
	}

	return 0;
}