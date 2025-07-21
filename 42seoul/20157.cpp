#include <iostream>
#include <numeric>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
map<ii, int> M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		int g = gcd(x, y);
		int dx = x / g, dy = y / g;
		M[{dx, dy}]++;
	}
	int answer = 0;
	for (auto [p, c] : M) {
		answer = max(answer, c);
	}
	cout << answer << '\n';
	return 0;
}