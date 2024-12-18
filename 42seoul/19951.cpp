#include <iostream>
#include <vector>

using namespace std;

int N, M, a, b, k;
int A[100001];
vector<int> V[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> k;
		V[a - 1].push_back(k);
		V[b].push_back(-k);
	}
	int sValue = 0;
	for (int i = 0; i < N; i++) {
		for (auto v : V[i])
			sValue += v;
		cout << A[i] + sValue << ' ';
	}
	cout << '\n';

	return 0;
}