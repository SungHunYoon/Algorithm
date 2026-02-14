#include <iostream>
#include <algorithm>

using namespace std;

int L, T, N;
int ant[70001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> T >> N;
	for (int i = 1; i <= N; i++) {
		int p;
		char d;
		cin >> p >> d;
		int dir = (d == 'L' ? -1 : 1);
		int m = (((p + dir * T) % (L * 2)) + (L * 2)) % (L * 2);
		ant[i] = (m <= L ? m : (L * 2) - m);
	}
	sort(ant + 1, ant + N + 1);
	for (int i = 1; i <= N; i++) {
		cout << ant[i] << ' ';
	}
	cout << '\n';

	return 0;
}