#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
string S[51];
bool visit[26];
int answer;

void dfs(int idx, int cnt) {
    if (K - 5 <= cnt) {
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            bool flag = true;
            for (int j = 0; j < S[i].size(); j++) {
                if (!visit[S[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                tmp++;
        }
        answer = max(answer, tmp);
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (!visit[i]) {
            visit[i] = true;
            dfs(i + 1, cnt + 1);
            visit[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        S[i] = S[i].substr(4, S[i].size() - 8);
    }
    visit['a' - 'a'] = visit['n' - 'a'] = visit['t' - 'a'] = visit['i' - 'a'] = visit['c' - 'a'] = true;
    dfs(0, 0);
    cout << answer << '\n';
    return 0;
}