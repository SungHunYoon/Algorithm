#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int answer = 0;
    while (n >= 5)
    {
        answer += n / 5;
        n = n / 5;
    }
    cout << answer << '\n';
    return (0);
}