// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_064.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int v[1000];
    ifstream f("date.in");
    int m, n = 0;
    int istart, iend;
    int ismax = 0, iemax = 0;
    while (f >> m)
    {
        v[n] = m;
        if (n > 0 && v[n] < v[n - 1])
            ++iend;
        else
            istart = iend = n;

        if (iend - istart > iemax - ismax)
        {
            ismax = istart;
            iemax = iend;
        }

        ++n;
    }

    for (int i = ismax; i <= iemax; ++i)
        cout << v[i] << ' ';

    return 0;
}
