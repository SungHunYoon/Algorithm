#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    
    cin >> t;
    vector<pair<int, int>> arr;
    arr.push_back({1, 0});
    arr.push_back({0, 1});
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for (int j = arr.size(); j <= n; j++)
        {
            int zero = arr[j - 2].first + arr[j - 1].first;
            int one = arr[j - 2].second + arr[j - 1].second;

            arr.push_back({zero, one});
        }
        cout << arr[n].first << " " << arr[n].second << '\n';
    }
    return (0);
}