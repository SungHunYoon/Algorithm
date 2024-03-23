#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> vec(101);
int dp[10001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> vec[i];
  sort(vec.begin(), vec.begin() + N);
  fill(dp, dp + K + 1, INT_MAX);
  for (int i = 0; i < N; i++) {
    for (int j = vec[i]; j <= K; j++) {
      int div = j / vec[i];
      if (div == 0) continue;
      int num = j % vec[i];
      if (num == 0)
        dp[j] = min(dp[j], div);
      else if (dp[j - vec[i]] != INT_MAX)
        dp[j] = min(dp[j], dp[j - vec[i]] + 1);
    }
  }
  // for (int i = 0; i <= K; i++) cout << "dp : " << dp[i] << '\n';
  if (dp[K] == INT_MAX)
    cout << "-1\n";
  else
    cout << dp[K] << '\n';
  return 0;
}