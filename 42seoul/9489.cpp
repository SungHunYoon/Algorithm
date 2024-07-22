#include <iostream>
#include <vector>

using namespace std;

int N, K;
int A[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> N >> K) {
		if (N == 0 && K == 0)
			break;
		cin >> A[0];
		vector<vector<int>> V[1001];
		vector<int> T;
		vector<int> Q[1001];
		T.push_back(A[0]);
		V[0].push_back(T);
		Q[0].push_back(0);
		T.clear();
		int L = 1;
		int C = 0;
		int I = 0;
		pair<int, int> P = {0, 0};
		for (int i = 1; i < N; i++) {
			cin >> A[i];
			if (A[i] - A[i - 1] > 1) {
				V[L].push_back(T);
				Q[L].push_back(I);
				T.clear();
				C++;
				if (C >= V[L - 1][I].size()) {
					C = 0;
					I++;
					if (I >= V[L - 1].size()) {
						I = 0;
						L++;
					}
				}
			}
			if (A[i] == K)
				P = {L, I};
			T.push_back(A[i]);
		}
		if (T.size() > 0) {
			V[L].push_back(T);
			Q[L].push_back(I);
		}
		int answer = 0;
		for (int i = 0; i < V[P.first].size(); i++) {
			if (Q[P.first][i] == P.second) {
				bool flag = true;
				for (int j = 0; j < V[P.first][i].size(); j++) {
					if (V[P.first][i][j] == K) {
						flag = false;
						break;
					}
				}
				if (!flag) continue;
				answer += V[P.first][i].size();
			}
		}
		cout << answer << '\n';
	}

	return 0;
}