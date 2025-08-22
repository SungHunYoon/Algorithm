#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N;
int A[601];
vector<iii> C;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			C.push_back({A[i] + A[j], i, j});
		}
	}
	sort(C.begin(), C.end());
	int answer = 2e9;
	for (int i = 0; i < C.size(); i++) {
		auto [sV, sA, sB] = C[i];
		for (int j = i + 1; j < C.size(); j++) {
			auto [eV, eA, eB] = C[j];
			if (!(sA == eA || sA == eB || sB == eA || sB == eB)) {
				answer = min(answer, eV - sV);
				break;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}