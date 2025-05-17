#include <iostream>

using namespace std;

string S;
int N;
string A[51];
int D[51];

int getDiffCount(int sIdx, int aIdx) {
	if (sIdx + A[aIdx].size() > S.size())
		return -1;
	int cnt = 0;
	int sCnt[26] = { 0, };
	int wCnt[26] = { 0, };
	for (int i = 0; i < A[aIdx].size(); i++) {
		sCnt[S[sIdx + i] - 'a']++;
		wCnt[A[aIdx][i] - 'a']++;
		if (S[sIdx + i] != A[aIdx][i])
			cnt++;
	}
	for (int i = 0; i < 26; i++) {
		if (sCnt[i] != wCnt[i])
			return -1;
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> N;
	for (int i = 0; i < S.size(); i++)
		D[i] = 1e9;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < N; j++) {
			int cnt = getDiffCount(i, j);
			if (cnt == -1) continue;
			int idx = i + A[j].size() - 1;
			D[idx] = min(D[idx], D[i - 1] + cnt);
		}
	}
	cout << (D[S.size() - 1] == 1e9 ? -1 : D[S.size() - 1]) << '\n';
	return 0;
}