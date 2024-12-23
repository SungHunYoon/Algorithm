#include <iostream>

using namespace std;

string N, X;
int K, P;

int num[10][7] = {
	{1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1}
};

int answer = 0;

int diffNum(int n, int s) {
	int cnt = 0;
	for (int i = 0; i < 7; i++)
		if (num[n][i] != num[s][i]) cnt++;
	return cnt;
}

void dfs(int k, int p, int maxV, string &curV) {
	if (k >= K) {
		int value = stoi(curV);
		if (curV != X && curV <= N && value)
			answer++;
		return;
	}
	for (int i = 0; i < 10; i++) {
		int diffCnt = diffNum(i, curV[k] - '0');
		if (diffCnt > p) continue;
		char c = curV[k];
		curV[k] = i + '0';
		dfs(k + 1, p - diffCnt, maxV, curV);
		curV[k] = c;
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K >> P >> X;
	while (X.size() != K) X.insert(X.begin(), '0');
	string T = X;
	dfs(0, P, stoi(N), T);
	cout << answer << '\n';
	return 0;
}