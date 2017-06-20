// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_048.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.in");
    ofstream g("bac.out");

    int v[9999 + 1] = {}, n;
    // numarul de numere ce vor fi citite
    f >> n;
    while (f >> n)
        ++v[n];

    for (int i = 0; i < 9999 + 1; ++i)
        if (v[i] == 1)
            g << i << ' ';

    return 0;
}
