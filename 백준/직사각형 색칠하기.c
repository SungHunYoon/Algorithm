#include <stdio.h>
#include <stdlib.h>

typedef struct s_info
{
    int size;
    int *sqaure;
    struct s_info *next;
} t_info;

t_info *create_node(int x1, int y1, int x2, int y2)
{
    t_info *info;

    info = (t_info *)malloc(sizeof(t_info));
    info->size = abs((x2 - x1) * (y2- y1));
    info->sqaure = (int *)malloc(sizeof(int) * 4);
    info->sqaure[0] = x1;
    info->sqaure[1] = y1;
    info->sqaure[2] = x2;
    info->sqaure[3] = y2;
    info->next = NULL;
    return (info);
}

void    push(t_info **list, t_info *node)
{
    if (*list == NULL)
        *list = node;
    else
    {
        node->next = *list;
        *list = node;
    }
}

int *sqaure(int x1, int y1, int x2, int y2)
{
    int *sqaure;

    sqaure = (int *)malloc(sizeof(int) * 4);
    sqaure[0] = x1;
    sqaure[1] = y1;
    sqaure[2] = x2;
    sqaure[3] = y2;
    return (sqaure);
}

void    cut(t_info **org, int *ref)
{
    t_info *list;
    int t[4];
    int lt, rt, rb, lb;

    list = NULL;
    while (*org != NULL)
    {
        t[0] = (*org)->sqaure[0];
        t[1] = (*org)->sqaure[1];
        t[2] = (*org)->sqaure[2];
        t[3] = (*org)->sqaure[3];
        // No cut
        if (t[0] >= ref[2] || t[1] >= ref[3] || t[2] <= ref[0] || t[3] <= ref[1])
            push(&list, create_node(t[0], t[1], t[2], t[3]));
        // X
        else if (t[0] >= ref[0] && t[1] >= ref[1] && t[2] <= ref[2] && t[3] <= ref[3])
        {

        }
        // Left cut
        else if (t[0] >= ref[0] && t[1] >= ref[1] && t[2] >= ref[2] && t[3] <= ref[3] && t[0] <= ref[2])
            push(&list, create_node(ref[2], t[1], t[2], t[3]));
        // Bottom cut
        else if (t[0] >= ref[0] && t[1] >= ref[1] && t[2] <= ref[2] && t[3] >= ref[3] && t[1] <= ref[3])
            push(&list, create_node(t[0], ref[3], t[2], t[3]));
        // Right cut
        else if (t[0] <= ref[0] && t[1] >= ref[1] && t[2] <= ref[2] && t[3] <= ref[3] && t[2] >= ref[0])
            push(&list, create_node(t[0], t[1], ref[0], t[3]));
        // Top cut
        else if (t[0] >= ref[0] && t[1] <= ref[1] && t[2] <= ref[2] && t[3] <= ref[3] && t[3] >= ref[1])
            push(&list, create_node(t[0], t[1], t[2], ref[1]));
        // - cut
        else if (t[0] <= ref[0] && ref[0] <= ref[2] && t[2] >= ref[2] && t[1] >= ref[1] && t[3] <= ref[3])
        {
            push(&list, create_node(t[0], t[1], ref[0], t[3]));
            push(&list, create_node(ref[2], t[1], t[2], t[3]));
        }
        // | cut
        else if (t[0] >= ref[0] && t[1] <= ref[1] && ref[1] <= ref[3] && t[3] >= ref[3] && t[2] <= ref[2])
        {
            push(&list, create_node(t[0], ref[3], t[2], t[3]));
            push(&list, create_node(t[0], t[1], t[2], ref[1]));
        }
        // ㅁ cut
        else if (t[0] <= ref[0] && t[1] <= ref[1] && t[2] >= ref[2] && t[3] >= ref[3])
        {
            push(&list, create_node(t[0], ref[3], t[2], t[3]));
            push(&list, create_node(t[0], ref[1], ref[0], ref[3]));
            push(&list, create_node(ref[2], ref[1], t[2], ref[3]));
            push(&list, create_node(t[0], t[1], t[2], ref[1]));
        }
        else
        {
            lt = t[0] <= ref[0] && ref[0] <= t[2] && t[1] <= ref[3] && t[3] >= ref[3];
            rt = t[0] <= ref[2] && ref[2] <= t[2] && t[1] <= ref[3] && t[3] >= ref[3];
            rb = t[0] <= ref[2] && ref[2] <= t[2] && t[1] <= ref[1] && ref[1] <= t[3];
            lb = t[0] <= ref[0] && ref[0] <= t[2] && t[1] <= ref[1] && ref[1] <= t[3];
            if (lt == 1)
            {
                if (rt == 1)
                {
                    push(&list, create_node(t[0], t[1], ref[0], ref[3]));
                    push(&list, create_node(ref[2], t[1], t[2], ref[3]));
                    push(&list, create_node(t[0], ref[3], t[2], t[3]));
                }
                else if (lb == 1)
                {
                    push(&list, create_node(t[0], ref[3], t[2], t[3]));
                    push(&list, create_node(t[0], ref[1], ref[0], ref[3]));
                    push(&list, create_node(t[0], t[1], t[2], ref[1]));
                }
                else
                {
                    push(&list, create_node(t[0], t[1], ref[0], t[3]));
                    push(&list, create_node(ref[0], ref[3], t[2], t[3]));
                }
            }
            else if (rt == 1)
            {
                if (rb == 1)
                {
                    push(&list, create_node(t[0], ref[3], t[2], t[3]));
                    push(&list, create_node(ref[2], ref[1], t[2], ref[3]));
                    push(&list, create_node(t[0], t[1], t[2], ref[1]));
                }
                else
                {
                    push(&list, create_node(t[0], ref[3], ref[2], t[3]));
                    push(&list, create_node(ref[2], t[1], t[2], t[3]));
                }
            }
            else if (rb == 1)
            {
                if (lb == 1)
                {
                    push(&list, create_node(t[0], ref[1], ref[0], t[3]));
                    push(&list, create_node(ref[2], ref[1], t[2], t[3]));
                    push(&list, create_node(t[0], t[1], t[2], ref[1]));
                }
                else
                {
                    push(&list, create_node(t[0], t[1], ref[2], ref[1]));
                    push(&list, create_node(ref[2], t[1], t[2], t[3]));
                }
            }
            else if (lb == 1)
            {
                push(&list, create_node(t[0], t[1], ref[0], t[3]));
                push(&list, create_node(ref[0], t[1], t[2], ref[1]));
            }
        }
        *org = (*org)->next;
    }
    //free(org);
    *org = list;
}

int *size_calculate(int **sqaure, int n)
{
    int i;
    int j;
    int *size;
    t_info **info;

    size = (int *)malloc(sizeof(int) * n);
    info = (t_info **)malloc(sizeof(t_info *) * n);
    i = 0;
    while (i < n)
    {
        info[i] = NULL;
        push(&info[i], create_node(sqaure[i][0], sqaure[i][1], sqaure[i][2], sqaure[i][3]));
        j = i + 1;
        while (j < n)
        {
            cut(&info[i], sqaure[j]);
            j++;
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        size[i] = 0;
        while (info[i] != NULL)
        {
            size[i] += info[i]->size;
            info[i] = info[i]->next;
        }
        i++;
    }
    return (size);
}

int *make_max(int *size, int n, int k)
{
    int i;
    int j;
    int mIndex;
    int *max;
    int tmp;

    max = (int *)malloc(sizeof(int) * k);
    i = 0;
    while (i < k)
    {
        tmp = -1;
        mIndex = -1;
        j = 0;
        while (j < n)
        {
            if (size[j] > tmp)
            {
                mIndex = j;
                tmp = size[j];
            }
            j++;
        }
        if (mIndex >= 0)
        {
            max[i] = mIndex + 1;
            size[mIndex] = -1;
        }
        i++;
    }
    return (max);
}

void quick_sort(int *arr, int left, int right)
{
    int pivot;
    int l;
    int r;
    int tmp;

    pivot = arr[(left + right) / 2];
    l = left;
    r = right;
    do
    {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left <= right)
        {
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    } while (left <= right);
    if (l < right)
        quick_sort(arr, l, right);
    if (r > left)
        quick_sort(arr, left, r);
}

int main(void)
{
    int N;
    int K;
    int i;
    int **sqaure;
    int *size;
    int *max;

    scanf("%d %d\n", &N, &K);
    sqaure = (int **)malloc(sizeof(int *) * N);
    i = 0;
    while (i < N)
    {
        sqaure[i] = (int *)malloc(sizeof(int) * 4);
        scanf("%d %d %d %d\n", &sqaure[i][0], &sqaure[i][1], &sqaure[i][2], &sqaure[i][3]);
        i++;
    }
    size = size_calculate(sqaure, N);
    
    printf("Size : ");
    for (int i = 0; i < N; i++)
        printf("%d, ", size[i]);
    printf("\n");
    
    max = make_max(size, N, K);
    quick_sort(max, 0, K - 1);
    i = 0;
    while (i < K)
    {
        printf("%d", max[i++]);
        if (i < K)
            printf(" ");
    }
    printf("\n");
    return (0);
}