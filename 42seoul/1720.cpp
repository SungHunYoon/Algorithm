#include <iostream>
#include <vector>

using namespace std;

int N;
long D[31], O[31];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	vector<int> dup;
	O[0] = 1; O[1] = 1; O[2] = 3;
	for (int i = 3; i <= N; i++) {
		O[i] = O[i - 1] + (O[i - 2] * 2);
	}
	for (int i = 2; i <= N; i++) {
		dup.push_back(O[i] - O[i - 1]);
		dup.push_back(O[i - 2]);
	}
	D[1] = 1; D[2] = 3;
	for (int i = 3; i <= N; i++) {
		D[i] = D[i - 1] + (D[i - 2] * 2) - dup[i - 3];
	}
	cout << D[N] << '\n';
	return 0;
}