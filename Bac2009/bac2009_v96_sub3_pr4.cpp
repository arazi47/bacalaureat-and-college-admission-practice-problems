// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_096.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int determina(int n, int v[], int a, int b)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (v[i] >= a && v[i] <= b)
            ++cnt;

    return cnt;
}

int main()
{
    int m, b, v[1000];
    ifstream f("bac.dat");
    f >> m >> b;
    for (int i = 0; i < m; ++i)
        f >> v[i];

    int a;
    f >> a; // capatul din stanga
    f >> b; // capatul din dreapta
    int amax = a, bmax = b;
    a = b;
    while (f >> b)
    {
        if (determina(m, v, a, b) > determina(m, v, amax, bmax))
        {
            amax = a;
            bmax = b;
        }
        a = b;
    }

    cout << amax << ' ' << bmax;

    return 0;
}
