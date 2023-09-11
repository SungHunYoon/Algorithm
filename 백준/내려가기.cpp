#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp1[3];
int dp2[3];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0)
        {
            dp1[0] = dp2[0] = a;
            dp1[1] = dp2[1] = b;
            dp1[2] = dp2[2] = c;
        }
        else
        {
            int tmp1 = a + min(dp1[0], dp1[1]);
            int tmp2 = b + min(dp1[0], min(dp1[1], dp1[2]));
            int tmp3 = c + min(dp1[1], dp1[2]);
            dp1[0] = tmp1;
            dp1[1] = tmp2;
            dp1[2] = tmp3;
            
            tmp1 = a + max(dp2[0], dp2[1]);
            tmp2 = b + max(dp2[0], max(dp2[1], dp2[2]));
            tmp3 = c + max(dp2[1], dp2[2]);
            dp2[0] = tmp1;
            dp2[1] = tmp2;
            dp2[2] = tmp3;
        }
    }
    int maxValue = max(dp2[0], max(dp2[1], dp2[2]));
    int minValue = min(dp1[0], min(dp1[1], dp1[2]));
    cout << maxValue << ' ' << minValue << '\n';
    return (0);
}