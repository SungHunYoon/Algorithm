#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    vector<vector<int>> arr;

    cin >> n;
    arr.assign(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            cin >> arr[i][j];

    sort(arr.begin(), arr.end());

    int max = 0;
    int index = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;

        for (int j = i; j < n; j++)
        {
            if (arr[i][0] - arr[j][1] >= 0)
            {
                temp += arr[i][0] - arr[j][1];
                if (temp > max)
                {
                    flag = 1;
                    index = i;
                    max = temp;
                }
            }
        }
    }
    if (flag == 0)
        cout << 0 << endl;
    else
        cout << arr[index][0] << endl;
    return (0);
}