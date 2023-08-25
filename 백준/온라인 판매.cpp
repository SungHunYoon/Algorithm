#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int m;
    vector<int> arr;

    cin >> n;
    cin >> m;
    arr.assign(m, 0);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int index = 0;
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        int temp = arr[i];
        if (n > m - i)
            temp *= m - i;
        else
            temp *= n;
        if (temp > answer)
        {
            answer = temp;
            index = i;
        }
    }
    cout << arr[index] << " " << answer << endl;
    return (0);
}