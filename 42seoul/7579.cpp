#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
pair<int, int> A[101];
long D[10000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int C = M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first;
		C = max(C, A[i].first);
	}
	for (int i = 1; i <= N; i++)
		cin >> A[i].second;
	fill(D + 1, D + C + 1, 1e15 + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = C; j >= 1; j--) {
			if (j - A[i].first >= 0)
				D[j] = min(D[j], D[j - A[i].first] + A[i].second);
			else
				D[j] = min(D[j], D[j + 1]);
		}
	}
	cout << D[M] << '\n';
	return 0;
}