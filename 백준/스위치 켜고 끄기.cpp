#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    vector<int> status;
    int m;
    vector<vector<int>> arr;

    cin >> n;
    status.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> status[i];
    cin >> m;
    arr.assign(m, vector<int> (2, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++)
            cin >> arr[i][j];
    for (int i = 0; i < m; i++)
    {
        int num = arr[i][1] - 1;

        if (arr[i][0] == 1)
        {
            for (int j = num; j < n; j += num + 1)
                status[j] = !status[j];
        }
        else
        {
            status[num] = !status[num];

            int index = 1;

            while (num - index >= 0 && num + index < n)
            {
                if (status[num - index] != status[num + index])
                    break;
                else
                {
                    status[num - index] = !status[num - index];
                    status[num + index] = !status[num + index];
                }
                index++;
            }
        }
    }
    int index = 0;

    while (n > 0)
    {
        int size;

        if (n >= 20)
            size = 20;
        else
            size = n;
        for (int i = 0; i < size; i++)
        {
            cout << status[index + i];
            if (i + 1 < size)
                cout << " ";
        }
        cout << endl;
        index += size;
        n -= size;
    }
    return (0);
}