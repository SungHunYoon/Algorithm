#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> square;
int dp[100001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    if (i * i > N) break;
    square.push_back(i * i);
  }
  fill(dp, dp + N + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < square.size(); j++) {
      if (i < square[j]) break;
      dp[i] = min(dp[i], dp[i - square[j]] + 1);
    }
  }
  cout << dp[N] << '\n';
  return 0;
}