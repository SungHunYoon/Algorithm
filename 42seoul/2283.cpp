#include <iostream>

using namespace std;

int N, K;
int A[1000001], B[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int s, e;
		cin >> s >> e;
		A[s]++; B[s]--;
		A[e]--; B[e]++;
	}
	int s = 0, e = 0, sCur = 0, eCur = 0, sum = 0;
	while (e <= 1000000) {
		if (sum == K) {
			break;
		} else if (sum > K) {
			sCur += B[s];
			sum += sCur;
			s++;
		} else {
			eCur += A[e];
			sum += eCur;
			e++;
		}
		
	}
	if (sum == K) {
		cout << s << " " << e << '\n';
	} else {
		cout << "0 0\n";
	}
	return 0;
}