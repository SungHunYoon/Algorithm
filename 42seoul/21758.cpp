#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100001];
int fSum[100002];
int bSum[100002];
int answer;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
        fSum[i] += fSum[i - 1] + arr[i];
    for (int i = N; i >= 1; i--)
        bSum[i] += bSum[i + 1] + arr[i];
    for (int i = 2; i <= N - 1; i++)
        answer = max(answer, (fSum[N] - fSum[1]) + (fSum[N] - fSum[i]) - arr[i]);
    for (int i = N - 1; i >= 2; i--)
        answer = max(answer, (bSum[1] - bSum[N]) + (bSum[1] - bSum[i]) - arr[i]);
    for (int i = 2; i <= N - 1; i++)
        answer = max(answer, fSum[N] - arr[1] - arr[N] + arr[i]);
    cout << answer << '\n';
    return 0;
}

// 4 4 9 1 9 4 4
// 4 8 17 18 27 31 35
// 4 8 17 18 27 31 35

// 2 5 4
// 2 7 11
// 4 9 11