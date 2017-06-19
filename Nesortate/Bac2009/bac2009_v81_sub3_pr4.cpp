// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_081.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.in");
    int v[501] = {}, n;
    while (f >> n)
        ++v[n];

    for (int i = 0; i < 501; ++i)
        if (v[i] == 1)
            cout << i << ' ';

    return 0;
}
