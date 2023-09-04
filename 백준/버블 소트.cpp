#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int> &arr, vector<int> &temp, int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int k = left;
    long long cnt = 0;
    while (i <= middle && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            if (k <= middle)
                cnt += 1;
            j++;
        }
        k++;
    }
    while (i <= middle)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = left; i <= right; i++)
        arr[i] = temp[i];
    return (cnt);
}

long long mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    long long cnt = 0;
    if (left < right)
    {
        int middle = (left + right) / 2;
        cnt += mergeSort(arr, temp, left, middle);
        cnt += mergeSort(arr, temp, middle + 1, right);
        cnt += merge(arr, temp, left, middle, right);
    }
    return (cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr (n, 0);
    vector<int> temp (n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << mergeSort(arr, temp, 0, n - 1) << '\n';
    return (0);
}