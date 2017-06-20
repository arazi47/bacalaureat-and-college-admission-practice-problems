// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_020.pdf
// Problema 3

#include <iostream>

using namespace std;

void nule(int a[100], int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] == 0 && a[j] != 0)
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

int main()
{
    int n, a[100];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    nule(a, n);

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';

    return 0;
}

