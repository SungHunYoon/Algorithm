#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[2001];
int B[2001];
int visit[2001][2001];

int dfs(int aIdx, int bIdx) {
	if (aIdx >= N || bIdx >= N)
		return 0;
	if (visit[aIdx][bIdx] != -1)
		return visit[aIdx][bIdx];
	visit[aIdx][bIdx] = max(dfs(aIdx + 1, bIdx), dfs(aIdx + 1, bIdx + 1));
	if (A[aIdx] > B[bIdx])
		visit[aIdx][bIdx] = max(visit[aIdx][bIdx], dfs(aIdx, bIdx + 1) + B[bIdx]);
	return visit[aIdx][bIdx];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	for (int i = 0; i < N; i++)
		fill(visit[i], visit[i] + N, -1);
	cout << dfs(0, 0) << '\n';
	return 0;
}