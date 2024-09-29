#include <iostream>
#include <map>

using namespace std;

int N, K;
int A[200001];
map<long, int> M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	long sum = 0;
	long answer = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		sum += A[i];
		if (sum == K)
			answer++;
		auto it = M.find(sum - K);
		if (it != M.end())
			answer += it->second;
		M[sum]++;
	}
	cout << answer << '\n';
	return 0;
}
