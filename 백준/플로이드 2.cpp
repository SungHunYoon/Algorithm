#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[101][101];
int trace[101][101];

void floydwashall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    trace[i][j] = trace[i][k];
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                arr[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        if (arr[s][e] > t)
        {
            arr[s][e] = t;
            trace[s][e] = e;
        }
    }
    floydwashall();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 1000000000)
                cout << "0 ";
            else
                cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (trace[i][j] == 0)
            {
                cout << "0\n";
                continue;
            }
            vector<int> answer;
            int t = trace[i][j];
            answer.push_back(i);
            while (t != j)
            {
                answer.push_back(t);
                t = trace[t][j];
            }
            answer.push_back(j);
            cout << answer.size() << ' ';
            for (int k = 0; k < answer.size(); k++)
                cout << answer[k] << ' ';
            cout << '\n';
        }
    }
    return (0);
}