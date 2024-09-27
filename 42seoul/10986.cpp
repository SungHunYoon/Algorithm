#include <iostream>

using namespace std;

int N, M;
int A[1000001];
int prefix[1000001];
int mod[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	long answer = 0;
	for (int i = 1; i <= N; i++) {
		prefix[i] = (prefix[i - 1] + A[i]) % M;
		if (prefix[i] == 0) answer++;
		mod[prefix[i]]++;
		if (mod[prefix[i]] > 1) answer += mod[prefix[i]] - 1;
	}
	cout << answer << '\n';
	return 0;
}
