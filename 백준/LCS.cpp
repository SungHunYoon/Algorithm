#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string a, b;
int arr[1001][1001];

int lcs()
{
    int ret = 0;
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            if (arr[i][j] > ret)
                ret = arr[i][j];
        }
    }
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    cout << lcs() << '\n';

    return (0);
}