#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
char O1, O2;
int P1, P2;
bool D[200001][7];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		fill(&D[0][0], &D[N + 1][0], 0);
		D[0][1] = 1;
		for (int i = 1; i <= N; i++) {
			cin >> O1 >> P1 >> O2 >> P2;
			for (int j = 0; j < 7; j++) {
				if (D[i - 1][j]) {
					if (O1 == '+')
						D[i][(j + P1) % 7] = 1;
					else
						D[i][(j * P1) % 7] = 1;
					if (O2 == '+')
						D[i][(j + P2) % 7] = 1;
					else
						D[i][(j * P2) % 7] = 1;
				}
			}
		}
		cout << (D[N][0] ? "LUCKY\n" : "UNLUCKY\n");
	}
	return 0;
}