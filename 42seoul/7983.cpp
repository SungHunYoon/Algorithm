#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> arr[1000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i].second >> arr[i].first;
    sort(arr, arr + N, greater<pair<int, int>>());
    int answer = arr[0].first - arr[0].second + 1;
    for (int i = 1; i < N; i++)
    {
        if (answer <= arr[i].first)
            answer -= arr[i].second;
        else
            answer = arr[i].first - arr[i].second + 1;
    }
    cout << answer - 1 << '\n';
    return 0;
}
