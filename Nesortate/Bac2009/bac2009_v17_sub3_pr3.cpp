// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_017.pdf
// Problema 3

#include <iostream>

using namespace std;

int interval(int a[100], int n)
{
    int cnt = 2; // cele doua capete
    int p = a[0];
    int q = a[n - 1];
    if (p > q)
    {
        p += q;
        q = p - q;
        p -= q;
    }

    for (int i = 1; i < n - 1; ++i)
    if (a[i] >= p && a[i] <= q)
            ++cnt;
}

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << interval(a, n);

    return 0;
}

