#include <iostream>

using namespace std;

string S, A, B;
int D[21][101][2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> A >> B;
	for (int i = 0; i < A.size(); i++) {
		if (S[0] == A[i])
			D[0][i][0]++;
		if (S[0] == B[i])
			D[0][i][1]++;
	}
	for (int i = 1; i < S.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			if (S[i] == A[j]) {
				for (int k = 0; k < j; k++)
					D[i][j][0] += D[i - 1][k][1];
			}
			if (S[i] == B[j]) {
				for (int k = 0; k < j; k++)
					D[i][j][1] += D[i - 1][k][0];
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < A.size(); i++) {
		answer += D[S.size() - 1][i][0];
		answer += D[S.size() - 1][i][1];
	}
	cout << answer << '\n';
	return 0;
}