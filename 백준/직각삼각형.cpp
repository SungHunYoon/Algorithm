#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[3];
    while (1)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            break;
        sort(arr, arr + 3);
        if (pow(arr[0], 2) + pow (arr[1], 2) == pow(arr[2], 2))
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return (0);
}