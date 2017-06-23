// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_057.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

bool exista(int m, int a[], int x)
{
    for (int i = 0; i < m; ++i)
        if (a[i] == x)
            return true;

    return false;
}

int main()
{
    ifstream f("intrare.txt");
    int n = 0, v[100];
    while (f >> v[n])
        ++n;

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] > v[j])
            {
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }

    int m = 0, a[10000];
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (!exista(m, a, v[i] + v[j]))
                a[m++] = v[i] + v[j];

    ofstream g("iesire.txt");
    for (int i = 0; i < m; ++i)
        g << a[i] << ' ';

    return 0;
}

