#include <iostream>

using namespace std;

string S1, S2;
int D[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S1 >> S2;
	for (int i = 1; i <= S1.size(); i += 3) {
		for (int j = 1; j <= S2.size(); j += 3) {
			int s1Idx = (i + 2) / 3, s2Idx = (j + 2) / 3;
			if (S1[i - 1] == S2[j - 1] && S1[i] == S2[j] && S1[i + 1] == S2[j + 1]) {
				D[s1Idx][s2Idx] = D[s1Idx - 1][s2Idx - 1] + 1;
			} else {
				D[s1Idx][s2Idx] = max(D[s1Idx - 1][s2Idx], D[s1Idx][s2Idx - 1]);
			}
		}
	}
	cout << D[(S1.size() + 2) / 3][(S2.size() + 2) / 3] << '\n';
	return 0;
}