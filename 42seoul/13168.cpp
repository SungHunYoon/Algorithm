#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, R, M, K;
map<string, int> S;
string A[201];
int D[101][101];
int rD[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> R;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		S.insert({s, i});
	}
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> A[i];
	fill(&D[0][0], &D[101][0], 1e9);
	fill(&rD[0][0], &rD[101][0], 1e9);
	for (int i = 1; i <= N; i++)
		D[i][i] = rD[i][i] = 0;
	cin >> K;
	for (int i = 0; i < K; i++) {
		string t, s, e;
		int c;
		cin >> t >> s >> e >> c;
		c *= 2;
		int sIdx = S[s], eIdx = S[e], d = c;
		if (t == "S-Train" || t == "V-Train")
			d = c / 2;
		else if (t == "ITX-Saemaeul" || t == "ITX-Cheongchun" || t == "Mugunghwa")
			d = 0;
		D[sIdx][eIdx] = min(D[sIdx][eIdx], c);
		D[eIdx][sIdx] = min(D[eIdx][sIdx], c);
		rD[sIdx][eIdx] = min(rD[sIdx][eIdx], d);
		rD[eIdx][sIdx] = min(rD[eIdx][sIdx], d);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				rD[i][j] = min(rD[i][j], rD[i][k] + rD[k][j]);
			}
		}
	}
	int cost = 0, rCost = 0;
	for (int i = 1; i < M; i++) {
		int sIdx = S[A[i - 1]];
		int eIdx = S[A[i]];
		cost += D[sIdx][eIdx];
		rCost += rD[sIdx][eIdx];
	}
	cout << (cost <= rCost + R * 2 ? "No\n" : "Yes\n");

	return 0;
}