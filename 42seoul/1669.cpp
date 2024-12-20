#include <iostream>
#include <cmath>

using namespace std;

int X, Y;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> X >> Y;
	int d = Y - X;
	int r = sqrt(d);
	int answer = 2 * r;
	if (d == 0) cout << "0\n";
	else if (r * r == d) cout << answer - 1 << '\n';
	else if (r * r + r >= d) cout << answer << '\n';
	else cout << answer + 1 << '\n';
	return 0;
}