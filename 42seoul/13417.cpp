#include <deque>
#include <iostream>

using namespace std;

int T, N;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    deque<char> dq;
    for (int j = 0; j < N; j++) {
      char tmp;
      cin >> tmp;
      if (dq.empty())
        dq.push_back(tmp);
      else {
        if (dq.front() >= tmp)
          dq.push_front(tmp);
        else
          dq.push_back(tmp);
      }
    }
    for (int j = 0; j < dq.size(); j++) cout << dq[j];
    cout << '\n';
  }

  return 0;
}