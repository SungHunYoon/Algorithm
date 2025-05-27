#include <iostream>

using namespace std;

int N, M;
int A[100001];
int T[400004];

int init(int n, int s, int e) {
    if (s == e)
        return T[n] = s;
    int mid = (s + e) / 2;
    int lIdx = init(n * 2, s, mid);
    int rIdx = init(n * 2 + 1, mid + 1, e);
    if (A[lIdx] > A[rIdx])
        T[n] = rIdx;
    else
        T[n] = lIdx;
    return T[n];
}

int update(int n, int s, int e, int idx, int v) {
    if (idx > e || idx < s)
        return T[n];
    if (idx <= s && e <= idx) {
        A[s] = v;
        return T[n];
    }
    int mid = (s + e) / 2;
    int lIdx = update(n * 2, s, mid, idx, v);
    int rIdx = update(n * 2 + 1, mid + 1, e, idx, v);
    if (A[lIdx] > A[rIdx])
        T[n] = rIdx;
    else
        T[n] = lIdx;
    return T[n];
}

int query(int n, int s, int e, int l, int r) {
    if (l > e || r < s)
        return 0;
    if (l <= s && e <= r)
        return T[n];
    int mid = (s + e) / 2;
    int lIdx = query(n * 2, s, mid, l, r);
    int rIdx = query(n * 2 + 1, mid + 1, e, l, r);
    if (lIdx == 0)
        return rIdx;
    if (rIdx == 0)
        return lIdx;
    if (A[lIdx] > A[rIdx])
        return rIdx;
    else
        return lIdx;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);
    cin >> M;
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 1, N, b, c);
        else
            cout << query(1, 1, N, b, c) << '\n';
    }
    return 0;
}