#include <iostream>
#include <vector>

using namespace std;

int comb(vector<int> arr, int r, int s, int sum, int depth)
{
    int cnt = 0;

    if (r == 0)
    {
        if (sum == s)
            return (1);
    }
    else if (depth == arr.size())
        return (0);
    else
    {
        cnt += comb(arr, r, s, sum, depth + 1);
        sum += arr[depth];
        cnt += comb(arr, r - 1, s, sum, depth + 1);
    }
    return (cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<int> arr (n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int answer = 0;
    for (int i = 1; i <= n; i++)
        answer += comb(arr, i, s, 0, 0);
    cout << answer << '\n';
    return (0);
}