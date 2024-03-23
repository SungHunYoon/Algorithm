#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int, int> > stk;
long long answer;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int f;
    cin >> f;
    if (f == 1) {
      int score, time;
      cin >> score >> time;
      stk.push({score, time});
    }
    if (!stk.empty()) {
      auto top = stk.top();
      stk.pop();
      top.second--;
      if (top.second > 0)
        stk.push(top);
      else
        answer += top.first;
    }
  }
  cout << answer << '\n';
  return 0;
}