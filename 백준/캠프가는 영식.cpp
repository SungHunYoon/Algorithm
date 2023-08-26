#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    int t;
    vector<vector<int>> arr;

    cin >> n;
    cin >> t;
    arr.assign(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    int answer = -1;
    for (int i = 0; i < n; i++)
    {
        if (t <= arr[i][0] + arr[i][1] * arr[i][2])
        {
            for (int j = 0; j < arr[i][2]; j++)
            {
                int stop = arr[i][0] + (arr[i][1] * j);
                if (t <= stop)
                {
                    if (answer == -1 || answer > stop - t)
                        answer = stop -t; 
                    break;
                }
            }
        }
    }
    cout << answer << endl;
    return (0);
}