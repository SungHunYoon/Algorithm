#include <iostream>
#include <algorithm>

using namespace std;

long A, B;
bool table[10000001];
long answer;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B;
	table[1] = true;
	for (__int128_t i = 2; i <= 10000000; i++) {
		if (table[i]) continue;
		for (__int128_t j = i * 2; j <= 10000000; j += i)
			table[j] = true;
		for (__int128_t j = i * i; j <= B; j *= i) {
			if (j >= A)
				answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}