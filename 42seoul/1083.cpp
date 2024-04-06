#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int arr[51];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> S;
    for (int i = 0; i < N && S > 0; i++)
    {
        int maxValue = arr[i];
        int maxIndex = i;
        for (int j = i; j < N; j++)
        {
            if (maxValue < arr[j] && S - j + i >= 0)
            {
                maxValue = arr[j];
                maxIndex = j;
            }
        }
        for (int j = maxIndex; j > i; j--)
            swap(arr[j], arr[j - 1]);
        S -= maxIndex - i;
    }
    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}

// 1 2 3 5 4
// 1 2 5 3 4
// 1 5 2 3 4
// 5 1 2 3 4

