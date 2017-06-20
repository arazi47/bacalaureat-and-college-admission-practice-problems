// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_008.pdf
// Problema 4

#include <iostream>

using namespace std;

// m = 5
// v[] = 2 4 8 10 14
// n = 3
// p[] = 3 5 11
int main()
{
    int m, v[100], n, p[100];
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> v[i];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    int a = 0, b = 0;
    int rez[200], k = 0;
    while (a < n && b < m)
    {
        rez[k++] = v[a++];
        rez[k++] = p[b++];
    }

    if (a == m && b + 1 < n){
            while (p[b] < rez[k])
                ++b;
        rez[k++] = p[b++];
    }

    else if (b == n && a + 1 < m)
    {
        while (v[a] < rez[k])
            ++a;
        rez[k++] = v[a - 1];

    }

    for (int i = 0; i < k; ++i)
        cout << rez[i] << ' ';

    return 0;
}
