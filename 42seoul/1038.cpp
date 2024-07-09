#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<long> answer;

void dfs(int idx, int prev, long num) {
	answer.push_back(num);
	for (int i = prev + 1; i < 10; i++)
		dfs(idx + 1, i, num + (i * pow(10, idx + 1)));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < 10; i++)
		dfs(0, i, i);
	sort(answer.begin(), answer.end());
	if (N >= answer.size())
		cout << "-1\n";
	else
		cout << answer[N] << '\n';
	return 0;
}