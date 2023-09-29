#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int arr[11][11];
int temp[11];
bool visit[11];
int answer;

void dfs(int index)
{
    if (index == n)
    {
        if (temp[0] != k)
            return;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int s = temp[i];
            int e = temp[i + 1];
            sum += arr[s][e];
        }
        answer = min(answer, sum);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            temp[index] = i;
            dfs(index + 1);
            visit[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] > arr[i][l] + arr[l][j])
                    arr[i][j] = arr[i][l] + arr[l][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
        temp[i] = i;
    
    answer = 1000000000;
    dfs(0);
    /*
    do
    {
        if (temp[0] != k)
            continue;
        int sum = 0;
        int s = 0, e = 1;
        for (int i = 0; i < n - 1; i++)
        {
            int s = temp[i];
            int e = temp[i + 1];
            sum += arr[s][e];
        }
        answer = min(answer, sum);
    } while(next_permutation(temp, temp + n));
    */
    cout << answer << '\n';
    return (0);
}