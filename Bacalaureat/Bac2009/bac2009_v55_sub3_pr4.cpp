// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_055.pdf
// Problema 4

#include <iostream>

using namespace std;

int concatALaB(int a, int b)
{
    int v[10], n = 0;
    while (b)
    {
        v[n++] = b % 10;
        b /= 10;
    }
    --n;
    while (n >= 0)
    {
        a = a * 10 + v[n];
        --n;
    }

    return a;
}

int main()
{
    int n, a[100], b[100];
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    int c[100];
    for (int i = 0; i < n; ++i)
        if (a[i] < b[i])
            c[i] = concatALaB(a[i], b[i]);
        else
            c[i] = concatALaB(b[i], a[i]);

    for (int i = 0; i < n; ++i)
        cout << c[i] << ' ';

    return 0;
}
