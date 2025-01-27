#include <iostream>

using namespace std;

int D, P;
int L[351], C[351];
int DP[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> D >> P;
	for (int i = 1; i <= P; i++)
		cin >> L[i] >> C[i];
	for (int i = 1; i <= P; i++) {
		DP[0] = C[i];
		for (int j = D; j >= L[i]; j--)
			DP[j] = max(DP[j], min(C[i], DP[j - L[i]]));
	}
	cout << DP[D] << '\n';
	return 0;
}