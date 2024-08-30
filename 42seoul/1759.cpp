#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
char A[15];
bool visit[15];
char table[] = {'a', 'e', 'i', 'o', 'u'};
vector<string> s;

bool checkTable(char c) {
	for (int i = 0; i < 5; i++)
		if (c == table[i])
			return true;
	return false;
}

bool findTable(string str) {
	bool flag1 = false;
	bool flag2 = false;
	int cnt = 0;

	for (int i = 0; i < str.size(); i++) {
		if (checkTable(str[i]))
			flag1 = true;
		else
			cnt++;
		if (cnt >= 2)
			flag2 = true;
		if (flag1 && flag2)
			return true;
	}
	return false;
}

void dfs(string str, int prev, int idx) {
	if (idx >= L) {
		if (findTable(str))
			s.push_back(str);
		return;
	}
	for (int i = prev; i < C; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(str + A[i], i, idx + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> A[i];
	sort(A, A + C);
	dfs("", 0, 0);
	for (auto str : s)
		cout << str << '\n';
	return 0;
}
