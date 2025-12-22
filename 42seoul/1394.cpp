#include <iostream>

using namespace std;

string S, E;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> E;
	int answer = 0;
	for (int i = 0; i < E.size(); i++) {
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == E[i]) {
				answer = (answer * S.size() + j + 1) % 900528;
				break;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}