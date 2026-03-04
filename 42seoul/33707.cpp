#include <iostream>

using namespace std;

int N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int r = 1, c = 2, answer;
	while (1) {
		cout << "? " << r << " " << c << "\n" << flush;
		cin >> answer;
		if (answer == 1) {
			return 0;
		}
		c += 2;
		if (c > M) {
			r += 1;
			c = (r % 2 ? 2 : 1);
		}
	}
	return 0;
}