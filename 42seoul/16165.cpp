#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int N, M;
map<string, set<string> > m;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string team;
    int num;
    cin >> team >> num;
    for (int j = 0; j < num; j++) {
      string member;
      cin >> member;
      m[team].insert(member);
    }
  }
  for (int i = 0; i < M; i++) {
    string tmp;
    int num;
    cin >> tmp >> num;
    if (num == 0) {
      for (auto it = m[tmp].begin(); it != m[tmp].end(); it++)
        cout << *it << '\n';
    } else {
      for (auto it = m.begin(); it != m.end(); it++) {
        if ((*it).second.find(tmp) != (*it).second.end())
          cout << (*it).first << '\n';
      }
    }
  }
  return 0;
}