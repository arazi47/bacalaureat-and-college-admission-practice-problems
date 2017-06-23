// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_047.pdf
// Problema 4

#include <iostream>

using namespace std;

int cif(int nr, int &s)
{
    s = 0;
    while (nr)
    {
        s += (nr % 10);
        nr /= 10;
    }

    return s;
}

int main()
{
    int n, v[25];
    cin >> n;
    int smax = 0;
    int s;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        cif(v[i], s);
        if (s > smax)
            smax = s;
    }

    for (int i = 0; i < n; ++i)
    {
        cif(v[i], s);
        if (s == smax)
            cout << v[i] << ' ';
    }

    return 0;
}
