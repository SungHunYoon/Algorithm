#include <algorithm>
#include <iostream>

using namespace std;

int N;
int dp[1500001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    dp[i] = max(dp[i - 1], dp[i]);
    if (i + p.first - 1 > N) continue;
    dp[i + p.first - 1] = max(dp[i + p.first - 1], dp[i - 1] + p.second);
  }
  cout << dp[N] << '\n';

  return 0;
}