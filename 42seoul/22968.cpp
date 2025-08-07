#include <iostream>

using namespace std;

int T, V;
int D[43];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	D[1] = 1; D[2] = 2;
	for (int i = 3; i <= 42; i++) {
		D[i] = 1 + D[i - 1] + D[i - 2];
	}
	while (T--) {
		cin >> V;
		int answer = 42;
		for (int i = 1; i <= 42; i++) {
			if (D[i] > V) {
				answer = i - 1;
				break;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}