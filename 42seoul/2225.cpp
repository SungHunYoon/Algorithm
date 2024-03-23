#include <iostream>

using namespace std;

int N, K;
long long dp[201];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> K;
  for (int i = 1; i <= K; i++) dp[i] = i;
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      dp[j] = (dp[j - 1] + dp[j]) % 1000000000;
    }
  }
  cout << dp[K] << '\n';

  return 0;
}