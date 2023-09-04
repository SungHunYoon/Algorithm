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

    int arr[10001] = { 0, };
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[num]++;
    }
    for (int i = 1; i < 10001; i++)
    {
        if (arr[i] > 0)
        {
            for (int j = 0; j < arr[i]; j++)
                cout << i << '\n';
        }
    }
    return (0);
}