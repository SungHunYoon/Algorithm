#include <iostream>

using namespace std;

int N;
int dp[1001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 1;
  dp[4] = 1;
  for (int i = 5; i <= N; i++) {
    if (dp[i - 4] % 2 == 0)
      dp[i] = dp[i - 4] + 1;
    else if (dp[i - 3] % 2 == 0)
      dp[i] = dp[i - 3] + 1;
    else
      dp[i] = dp[i - 1] + 1;
  }
  if (dp[N] % 2 == 1)
    cout << "SK\n";
  else
    cout << "CY\n";
  return 0;
}