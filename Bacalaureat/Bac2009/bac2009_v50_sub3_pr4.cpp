// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_050.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.in");
    int n, v[9999 + 1] = {};
    // marimea sirului
    f >> n;

    while (f >> n)
        ++v[n];

    for (int i = 0; i < 9999 + 1; ++i)
        if (v[i] >= 2)
            cout << i << ' ';

    return 0;
}
