#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
int arr[100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int answer = 1000000000;
    int sum = 0;
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        while (sum < s && e < n)
            sum += arr[e++];
        if (sum >= s)
            answer = min(answer, e - i);
        sum -= arr[i];
    }
    if (answer == 1000000000)
        cout << "0\n";
    else
        cout << answer << '\n';
    return (0);
}