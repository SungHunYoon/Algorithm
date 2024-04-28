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
    long long answer = 0;
    for (int i = 0, idx = 1; i < N; i++)
    {
        if (arr[i] < idx)
            continue;
        else if (arr[i] == idx)
        {
            idx++;
            continue;
        }
        int cnt = abs(idx - arr[i]);
        answer += cnt;
        idx++;
    }
    cout << answer << "\n";
    return 0;
}