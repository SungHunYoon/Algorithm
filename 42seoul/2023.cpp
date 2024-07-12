#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> answer;

bool isPrime(int dest) {
	for (int i = 2; i < dest; i++) {
		if (dest % i == 0) return false;
	}
	return true;
}

void dfs(int idx, int num) {
	if (idx >= N) {
		answer.push_back(num);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		int dest = num * 10 + i;
		if (isPrime(dest))
			dfs(idx + 1, dest);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 2; i <= 9; i++) {
		if (isPrime(i))
			dfs(1, i);
	}
	sort(answer.begin(), answer.end());
	for (auto i : answer)
		cout << i << '\n';
	return 0;
}