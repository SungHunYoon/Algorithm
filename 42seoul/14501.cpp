#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > arr(16);
int dp[16];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;

  for (int i = 1; i <= N; i++) {
    if (i + arr[i].first - 1 <= N) {
      dp[i + arr[i].first - 1] =
          max(dp[i + arr[i].first - 1], dp[i - 1] + arr[i].second);
      for (int j = i + arr[i].first - 1; j <= N; j++)
        dp[j] = max(dp[i + arr[i].first - 1], dp[j]);
    }
  }
  cout << dp[N] << '\n';
  return 0;
}