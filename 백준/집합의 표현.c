#include <stdio.h>
#include <stdlib.h>

int find(int *parent, int i)
{
    if (i == parent[i])
        return (i);
    parent[i] = find(parent, parent[i]);
    //return (find(parent, parent[i]));
    return (parent[i]);
}

int is_union(int *parent, int i, int j)
{
    return (find(parent, i) == find(parent, j));
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

int main(void)
{
    int n;
    int m;
    int i;
    int c;
    int a;
    int b;
    int *parent;

    scanf("%d %d\n", &n, &m);
    parent = (int *)malloc(sizeof(int) * (n + 1));
    i = 0;
    while (i < n + 1)
    {
        parent[i] = i;
        i++;
    }
    i = 0;
    while (i < m)
    {
        scanf("%d %d %d\n", &c, &a, &b);
        if (c == 0)
            make_union(parent, a, b);
        else
        {
            if(is_union(parent, a, b) == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        i++;
    }
    return (0);
}