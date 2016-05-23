#include <iostream>

using namespace std;

int A[100];

void quick(int low, int high)
{
    int i = low, j = high, pivot = A[(low + high) / 2];

    do
    {
        while (i < high && A[i] < pivot)
            ++i;
        while (j > low && A[j] > pivot)
            --j;

        if (i <= j)
        {
            swap(A[i], A[j]);
            ++i;
            --j;
        }
        
    } while (i <= j);

    if (i < high)
        quick(i, high);
    if (j > low)
        quick(low, j);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    quick(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}
