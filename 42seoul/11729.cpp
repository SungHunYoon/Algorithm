#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> answer;

void recursive(int n, int from, int by, int to) {
	if (n == 0) {
		return;
	}
	recursive(n - 1, from, to, by);
	answer.push_back({from, to});
	recursive(n - 1, by, from, to);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	recursive(N, 1, 2, 3);
	cout << answer.size() << '\n';
	for (auto [a, b] : answer)
		cout << a << " " << b << '\n';
	return 0;
}
