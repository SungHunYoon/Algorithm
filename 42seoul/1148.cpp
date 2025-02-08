#include <iostream>
#include <algorithm>

using namespace std;

int D[200001][26];
int T[26];
bool V[26];
int A[26];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	int idx = 0;
	while (cin >> s) {
		if (s == "-")
			break;
		for (int i = 0; i < s.size(); i++)
			D[idx][s[i] - 'A']++;
		idx++;
	}
	while (cin >> s) {
		if (s == "#")
			break;
		for (int i = 0; i < 26; i++)
			A[i] = T[i] = V[i] = 0;
		for (int i = 0; i < s.size(); i++)
			T[s[i] - 'A']++;
		for (int i = 0; i < s.size(); i++) {
			if (V[s[i] - 'A']) continue;
			V[s[i] - 'A'] = true;
			for (int j = 0; j < idx; j++) {
				if (!D[j][s[i] - 'A']) continue;
				bool flag = true;
				for (int k = 0; k < 26; k++) {
					if (!D[j][k]) continue;
					if (D[j][k] > T[k]) {
						flag = false;
						break;
					}
				}
			if (flag)
				A[s[i] - 'A']++;
			}
		}
		string minStr, maxStr;
		int minCnt = 1e9, maxCnt = 0;
		for (int i = 0; i < 26; i++) {
			if (!T[i]) continue;
			if (A[i] < minCnt) {
				minStr.clear();
				minCnt = A[i];
			}
			if (A[i] == minCnt)
				minStr.push_back('A' + i);
			if (A[i] > maxCnt) {
				maxStr.clear();
				maxCnt = A[i];
			}
			if (A[i] == maxCnt)
				maxStr.push_back('A' + i);
		}
		cout << minStr << " " << minCnt << " " << maxStr << " " << maxCnt << '\n';
	}

	return 0;
}