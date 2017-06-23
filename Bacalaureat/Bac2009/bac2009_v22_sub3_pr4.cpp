// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_022.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int a, b, nr;
    f >> a; // numarul de perechi, dar nu-l folosesc
    while (f >> a >> b)
    {
        nr = 1;
        while (2 * nr < b)
            nr *= 2;

        if (nr >= a && nr <= b)
            cout << nr << ' ';
        else
            cout << 0 << ' ';
    }

    return 0;
}

