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

    int table[15][15];
    for (int i = 0; i < 15; i++)
    {
        for (int j = 1; j < 15; j++)
        {
            if (i == 0)
                table[i][j] = j;
            else
            {
                table[i][j] = 0;
                for (int k = 1; k <= j; k++)
                    table[i][j] += table[i - 1][k];
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        int k, n;
        cin >> k >> n;
        cout << table[k][n] << '\n';
    }
    return (0);
}