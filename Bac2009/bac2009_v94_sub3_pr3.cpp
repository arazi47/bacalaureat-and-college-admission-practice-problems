// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_094.pdf
// Problema 3

#include <iostream>

using namespace std;

int f(int n, int v[100])
{
    int i = 0;
    while (v[i] < v[i + 1] && i < n - 1)
        ++i;

    // sir crescator
    if (i == n - 1)
        return 1;

    i = 0;
    while (v[i] > v[i + 1] && i < n - 1)
        ++i;

    // sir descrescator
    if (i == n - 1)
        return 2;

    i = 0;
    while (v[i] == v[i + 1] && i < n - 1)
        ++i;

    // sir constant
    if (i == n - 1)
        return 0;

    return -1;
}

int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << f(n, v);

    return 0;
}
