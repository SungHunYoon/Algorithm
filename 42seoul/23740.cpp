#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N;
iii A[200001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		auto &[s, e, c] = A[i];
		cin >> s >> e >> c;
	}
	sort(A, A + N);
	vector<iii> answer;
	auto [stdS, stdE, minV] = A[0];
	for (int i = 1; i < N; i++) {
		auto &[s, e, c] = A[i];
		if (stdE >= s) {
			stdE = max(stdE, e);
			minV = min(minV, c);
		} else {
			answer.push_back({stdS, stdE, minV}); 
			stdS = s;
			stdE = e;
			minV = c;
		}
	}
	answer.push_back({stdS, stdE, minV});
	cout << answer.size() << '\n';
	for (auto [s, e, c] : answer)
		cout << s << " " << e << " " << c << '\n';
	return 0;
}