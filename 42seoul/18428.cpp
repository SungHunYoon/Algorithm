#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[6][6];
vector<pair<int, int>> T;

bool check() {
    for (int i = 0; i < T.size(); i++) {
        for (int j = T[i].first; j >= 0; j--) {
            if (A[j][T[i].second] == 1)
                return false;
            else if (A[j][T[i].second] == 3)
                break;
        }
        for (int j = T[i].first; j < N; j++) {
            if (A[j][T[i].second] == 1)
                return false;
            else if (A[j][T[i].second] == 3)
                break;
        }
        for (int j = T[i].second; j >= 0; j--) {
            if (A[T[i].first][j] == 1)
                return false;
            else if (A[T[i].first][j] == 3)
                break;
        }
        for (int j = T[i].second; j < N; j++) {
            if (A[T[i].first][j] == 1)
                return false;
            else if (A[T[i].first][j] == 3)
                break;
        }
    }
    return true;
}

bool dfs(int x, int y, int cnt) {
    if (x >= N) {
        x = 0;
        y++;
    }
    if (y >= N)
        return false;
    if (cnt >= 3) {
        if (check())
            return true;
        return false;
    }
    if (dfs(x + 1, y, cnt))
        return true;
    if (A[y][x] == 0) {
        A[y][x] = 3;
        if (dfs(x + 1, y, cnt + 1))
            return true;
        A[y][x] = 0;
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == 'X')
                A[i][j] = 0;
            else if (c == 'S')
                A[i][j] = 1;
            else {
                A[i][j] = 2;
                T.push_back({i, j});
            }
        }
    }
    if (dfs(0, 0, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}