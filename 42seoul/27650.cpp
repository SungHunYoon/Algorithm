#include <iostream>
#include <vector>

using namespace std;

int N;
bool T[5000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (T[i]) continue;
		for (int j = i + i; j <= N; j += i) {
			T[j] = true;
		}
	}
	vector<int> primes;
	for (int i = 2; i <= N; i++) {
		if (T[i]) continue;
		primes.push_back(i);
	}
	int s = -1, e = primes.size();
	while (s + 1 < e) {
		int mid = (s + e) / 2;
		cout << "? " << primes[mid] << '\n' << flush;
		int result;
		cin >> result;
		if (result == 0) {
			e = mid;
		} else {
			s = mid;
		}
	}
	cout << "! " << primes[e] << '\n';
	return 0;
}