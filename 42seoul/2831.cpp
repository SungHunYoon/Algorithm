#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T;
vector<int> P;
vector<int> M;
int W[100001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T;
        if (T > 0)
            P.push_back(T);
        else
            M.push_back(T);
    }
    for (int i = 0; i < N; i++)
        cin >> W[i];
    sort(P.begin(), P.end());
    sort(M.begin(), M.end());
    sort(W, W + N);
    int answer = 0;
    int start = 0, end = N - 1;
    while (start < M.size() && end >= 0 && W[end] > 0) {
        if (abs(M[start]) > abs(W[end])) {
            start++;
            end--;
            answer++;
        } else
            end--;
    }
    start = 0; end = P.size() - 1;
    while (start < N && W[start] < 0 && end >= 0) {
        if (abs(P[end]) < abs(W[start])) {
            start++;
            end--;
            answer++;
        } else {
            end--;
        }
    }
    cout << answer << '\n';
    return 0;
}