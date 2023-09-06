#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int d[n + 1];
        d[1] = 1;
        d[2] = 2;
        d[3] = 4;
        for (int j = 4; j <= n; j++)
            d[j] = d[j - 1] + d[j - 2] + d[j - 3];
        cout << d[n] << '\n';
    }
    return (0);
}