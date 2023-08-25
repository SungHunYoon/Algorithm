#include <iostream>
#include <vector>

using namespace std;

int find_index(vector<int> arr, int n, int score)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (score > arr[i])
            return (i);
    }
    return (i);
}

int find_rank(vector<int> arr, int index, int score)
{
    int rank = 1;
    int prev = arr[0];
    int cnt = 0;
    int i;

    for (i = 0; i < index; i++)
    {
        if (prev > arr[i])
        {
            prev = arr[i];
            rank += cnt;
            cnt = 0;
        }
        cnt++;
    }
    if (prev > score)
        rank += cnt;
    return (rank);
}

int main(void)
{
    int n;
    int score;
    int p;
    int answer;

    cin >> n;
    cin >> score;
    cin >> p;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n == 0)
        cout << "1" << endl;
    else
    {
        int find = find_index(arr, n, score);
        if (find < p)
            cout << find_rank(arr, find, score) << endl;
        else
            cout << "-1" << endl;
    }
    return (0);
}