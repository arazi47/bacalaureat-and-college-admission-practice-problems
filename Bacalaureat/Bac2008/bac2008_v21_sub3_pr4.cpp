// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_021.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int n, k;
    f >> n >> k;
    int v[k], x;

    // citesc primele k elemente
    int smax = 0, imax = 0;
    for (int j = 0; j < k; ++j)
    {
        f >> v[j];
        smax += v[j];
    }

    int s = smax;
    int i = 0;
    // citesc tot cate un element
    while (f >> x)
    {
        ++i;

        // scot din suma primul element
        // si il introduc pe ultimul
        s -= v[0];
        s += x;

        // in v vom avea tot cate k elemente
        for (int j = 0; j < k - 1; ++j)
            v[j] = v[j + 1];

        v[k - 1] = x;

        if (s > smax)
        {
            smax = s;
            imax = i;
        }

    }

    // + 1 pentru ca am inceput indexarea de la 0
    cout << imax + 1;

    return 0;
}

