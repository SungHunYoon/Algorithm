#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int N, Z;
char X, Y;
int C[53][53];
int F[53][53];

int networkFlow(int source, int sink) {
	int totalFlow = 0;
	while (1) {
		queue<int> q;
		vector<int> P(53, -1);
		P[source] = source;
		q.push(source);
		while (!q.empty() && P[sink] == -1) {
			int here = q.front(); q.pop();
			for (int i = 0; i < 52; i++) {
				if (C[here][i] <= F[here][i]) continue;
				if (P[i] != -1) continue;
				q.push(i);
				P[i] = here;
			}
		}
		if (P[sink] == -1)
			break;
		int maxF = 1e9;
		for (int t = sink; t != source; t = P[t])
			maxF = min(maxF, C[P[t]][t] - F[P[t]][t]);
		for (int t = sink; t != source; t = P[t]) {
			F[P[t]][t] += maxF;
			F[t][P[t]] -= maxF;
		}
		totalFlow += maxF;
	}
	return totalFlow;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y >> Z;
		if (X >= 'a') X = X - 'a' + 26;
		else X = X - 'A';
		if (Y >= 'a') Y = Y - 'a' + 26;
		else Y = Y - 'A';
		C[X][Y] += Z;
		C[Y][X] += Z;
	}
	cout << networkFlow(0, 25) << '\n';
	return 0;
}