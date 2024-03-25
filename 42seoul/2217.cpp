#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    int answer = 0;
    for (int i = 0; i < N; i++)
        answer = max(answer, arr[i] * (N - i));
    cout << answer << '\n';
    return 0;
}