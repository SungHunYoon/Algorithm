#include <stdio.h>
#include <stdlib.h>

int find(int *parent, int i)
{
    if (parent[i] == i)
        return (i);
    parent[i] = find(parent, parent[i]);
    return (parent[i]);
}

void make_union(int *parent, int i, int j)
{
    i = find(parent, i);
    j = find(parent, j);

    if (i != j)
    {
        if (i > j)
            parent[i] = j;
        else
            parent[j] = i;
    }
}

typedef struct s_list
{
    int             weight;
    int             node1;
    int             node2;
}   t_list;

void quickSort(t_list *list, int L, int R)
{
      int left = L, right = R;
      int pivot = list[(L + R) / 2].weight;
      t_list temp;
      do
      {
        while (list[left].weight < pivot)
            left++;
        while (list[right].weight > pivot)
            right--;
        if (left<= right)
        {
            temp = list[left];
            list[left] = list[right];
            list[right] = temp;
            left++;
            right--;
        }
      } while (left<= right);
    if (L < right)
        quickSort(list, L, right);
    if (left < R)
        quickSort(list, left, R);
}

int main(void)
{
    int     V;
    int     E;
    int     A;
    int     B;
    int     C;
    int     i;
    t_list  *list;
    int     *parent;
    int     weight;
    int     cnt;

    scanf("%d %d\n", &V, &E);
    parent = (int *)malloc(sizeof(int) * (V + 1));
    if (parent == NULL)
        return (0);
    i = 1;
    while (i < V + 1)
    {
        parent[i] = i;
        i++;
    }
    i = 0;
    list = (t_list *)malloc(sizeof(t_list) * E);
    while (i < E)
    {
        scanf("%d %d %d\n", &A, &B, &C);
        list[i].node1 = A;
        list[i].node2 = B;
        list[i].weight = C;
        i++;
    }
    quickSort(list, 0, E - 1);
    i = 0;
    weight = 0;
    cnt = 0;
    while (i < E)
    {
        if (find(parent, list[i].node1) != find(parent, list[i].node2))
        {
            make_union(parent, list[i].node1, list[i].node2);
            weight += list[i].weight;
            cnt++;
            if (cnt == V - 1)
                break;
        }
        i++;
    }
    printf("%d\n", weight);
    return (0);
}