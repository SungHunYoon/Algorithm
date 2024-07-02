#include <iostream>
#include <algorithm>

using namespace std;

int N, H;
int O[100001];
int E[100001];
int P[500001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		if (i % 2 == 0)
			E[i / 2] = n;
		else
			O[i / 2] = n;
	}
	sort(E, E + N / 2);
	sort(O, O + N / 2);
	int prevE = 0;
	int prevO = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = prevE; j < E[i]; j++)
			P[j] += N / 2 - i;
		prevE = E[i];
		for (int j = prevO; j < O[i]; j++)
			P[H - 1 - j] += N / 2 - i; 
		prevO = O[i];
	}
	int minValue = 1e9;
	int minCnt = 0;
	for (int i = 0; i < H; i++) {
		if (minValue > P[i]) {
			minValue = P[i];
			minCnt = 0;
		}
		if (minValue == P[i])
			minCnt++;
	}
	cout << minValue << ' ' << minCnt << '\n';
	return 0;
}