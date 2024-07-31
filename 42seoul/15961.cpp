#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, D, K, C;
int A[3000001];
map<int, int> M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int answer = 0;
	for (int i = 0; i < K; i++)
		M[A[i]]++;
	if (M.find(C) == M.end())
		answer = max(answer, (int)M.size() + 1);
	else
		answer = max(answer, (int)M.size());
	int start = 0, end = K;
	while (start < N) {
		auto it = M.find(A[start]);
		if (it != M.end()) {
			it->second--;
			if (it->second <= 0)
				M.erase(it);
		}
		start++;
		M[A[end]]++;
		end = (end + 1) % N;
		if (M.find(C) == M.end())
			answer = max(answer, (int)M.size() + 1);
		else
			answer = max(answer, (int)M.size());
	}
	cout << answer << '\n';
	return 0;
}