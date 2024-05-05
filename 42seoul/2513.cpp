#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, S;
pair<int, int> arr[30001];
vector<pair<int, int>> A, B;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
    {
        if (S > arr[i].first)
            A.push_back(arr[i]);
        else
            B.push_back(arr[i]);
    }
    reverse(B.begin(), B.end());
    int answer = 0;
    int modIdx = -1;
    int mod = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (modIdx != -1 && A[i].second + mod >= K)
        {
            A[i].second += mod - K;
            answer += (S - arr[modIdx].first) * 2;
            mod = 0;
            modIdx = -1;
        }
        answer += A[i].second / K * (S - A[i].first) * 2;
        mod += A[i].second % K;
        if (mod != 0 && modIdx == -1)
            modIdx = i;
    }
    if (modIdx != -1)
        answer += (S - A[modIdx].first) * 2;
    modIdx = -1;
    mod = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (modIdx != -1 && B[i].second + mod >= K)
        {
            B[i].second += mod - K;
            answer += (B[modIdx].first - S) * 2;
            mod = 0;
            modIdx = -1;
        }
        answer += B[i].second / K * (B[i].first - S) * 2;
        mod += B[i].second % K;
        if (mod != 0 && modIdx == -1)
            modIdx = i;
    }
    if (modIdx != -1)
        answer += (B[modIdx].first - S) * 2;
    cout << answer << '\n';
    return 0;
}