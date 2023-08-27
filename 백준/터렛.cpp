#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    vector<vector<int>> arr1;
    vector<vector<int>> arr2;
    
    cin >> t;
    arr1.assign(3, vector<int>(3, 0));
    arr2.assign(3, vector<int>(3, 0));
    for (int i = 0; i < t; i++)
    {
        cin >> arr1[i][0] >> arr1[i][1] >> arr1[i][2];
        cin >> arr2[i][0] >> arr2[i][1] >> arr2[i][2];
    }
    for (int i = 0; i < t; i++)
    {
        if (arr1[i][0] == arr2[i][0] && arr1[i][1] == arr2[i][1])
        {
            if (arr1[i][2] == arr2[i][2])
                cout << -1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
        {
            int distance = pow(arr2[i][0] - arr1[i][0], 2) + pow(arr2[i][1] - arr1[i][1], 2);
            int sum = pow(arr1[i][2] + arr2[i][2], 2);
            int sub = pow(arr1[i][2] - arr2[i][2], 2);
            if (distance < sum)
            {
                if (distance > sub)
                    cout << 2 << '\n';
                else if (distance == sub)
                    cout << 1 << '\n';
                else
                    cout << 0 << '\n';
            }
            else if (distance == sum)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
    return (0);
}