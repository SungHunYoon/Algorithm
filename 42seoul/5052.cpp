#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
string S[10001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> S[i];
        sort(S, S + N);
        bool flag = true;
        for (int i = 1; i < N; i++) {
            if (S[i].find(S[i - 1]) == 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}