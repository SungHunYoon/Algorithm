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
    bool table[1001] = { false, };
    table[1] = true;
    for (int i = 2; i <= 1001; i++)
    {
        if (table[i] == true)
            continue;
        for (int j = i * 2; j <= 1001; j += i)
            table[j] = true;
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (table[num] == false)
            answer++;
    }
    cout << answer << '\n';
    return (0);
}