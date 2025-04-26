#include <iostream>
#include <cmath>

using namespace std;

int K;
bool T[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	for (int i = 2; i <= K; i++) {
		if (T[i]) continue;
		for (int j = i + i; j <= K; j += i)
			T[j] = true;
	}
	int answer = 0;
	if (T[K]) {
		int i = 2, cnt = 1;
		while (K > 1) {
			if (K % i == 0) { 
				K /= i;
				cnt++;
			} else {
				while (T[++i]);
			}
		}
		while (cnt > 2) {
			cnt >>= 1;
			cnt++;
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}