#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int distance(int x1, int y1, int x2, int y2)
{
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x1, y1, x2, y2;
        int n;
        vector<vector<int>> arr;

        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        arr.assign(n, vector<int>(3, 0));
        int answer = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j][0] >> arr[j][1] >> arr[j][2];
            int start = distance(x1, y1, arr[j][0], arr[j][1]);
            int end = distance(x2, y2, arr[j][0], arr[j][1]);
            int r = pow(arr[j][2], 2);
            if ((start < r && end > r) || (start > r && end < r))
                answer++;
        }
        cout << answer << '\n';
    }
    return (0);
}