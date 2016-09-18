#include <iostream>

using namespace std;

int v[] = {12, 11, 13, 5, 6, 7};
int n = 6;

/* Function to merge the two halves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = v[l + i];
    for(j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    /* Merge the temp arrays back into v[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2; //l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

int main()
{
    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';

    return 0;
}
