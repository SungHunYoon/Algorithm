#include <iostream>
#include <algorithm>

using namespace std;

int N;
string S;
bool visit[20];
int answer = -1e9;

int calValue(int idx, int value, int value2) {
	if (idx == 0) value += value2;
	else {
		if (S[idx - 1] == '+')
			value += value2;
		else if (S[idx - 1] == '-')
			value -= value2;
		else if (S[idx - 1] == '*')
			value *= value2;
		else
			value /= value2;
	}
	return value;
}

void dfs(int idx, int value) {
	if (count(visit, visit + N, true) >= (N + 1) / 2) {
		answer = max(answer, value);
		return;
	}
	for (int i = idx; i < N; i += 2) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i + 2, calValue(i, value, S[i] - '0'));
			if (i + 2 < N && !visit[i + 2]) {
				visit[i + 2] = true;
				dfs(i + 4, calValue(i, value, calValue(i + 2, S[i] - '0', S[i + 2] - '0')));
				visit[i + 2] = false;
			}
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	dfs(0, 0);
	cout << answer << '\n';
	return 0;
}
