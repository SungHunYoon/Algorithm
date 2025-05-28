#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int T[10001][2];
int minL[10001], maxL[10001];
bool visited[10001];

int inorder(int idx, int level, int cnt) {
	if (idx == 0)
		return cnt;
	cnt = inorder(T[idx][0], level + 1, cnt);
	cnt++;
	M = max(M, level);
	minL[level] = min(minL[level], cnt);
	maxL[level] = max(maxL[level], cnt);
	cnt = inorder(T[idx][1], level + 1, cnt);
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n, l, r;
		cin >> n >> l >> r;
		if (l != -1) {
			T[n][0] = l;
			visited[l] = true;
		}
		if (r != -1) {
			T[n][1] = r;
			visited[r] = true;
		}
		minL[i] = 1e9;
	}
	int root = find(visited + 1, visited + N + 1, false) - visited;
	inorder(root, 1, 0);
	int answerIdx = 0, answer = 0;
	for (int i = 1; i <= M; i++) {
		int width = maxL[i] - minL[i] + 1;
		if (answer < width) {
			answerIdx = i;
			answer = width;
		}
	}
	cout << answerIdx << " " << answer << '\n';
	return 0;
}