#include <iostream>

using namespace std;

int K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	string T[] = { "Aa", "BB" };
	int mask = 1;
	while (mask < K) {
		mask <<= 1;
	}
	for (int i = 0, cnt = 0; i < mask && cnt < K; i++, cnt++) {
		string output;
		for (int j = 1; j < mask; j <<= 1) {
			output += T[((i & j) ? 1 : 0)];
		}
		cout << output << '\n';
	}
	return 0;
}