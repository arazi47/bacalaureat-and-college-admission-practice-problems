// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_041.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, v[10] = {};
    ifstream f("numere.txt");
    f >> n; // numarul de cifre
    while (f >> n)
        ++v[n];

    for (int i = 9; i >= 0; --i)
        if (v[i])
        {
            cout << i << ' ' << v[i];
            return 0;
        }

    return 0;
}
