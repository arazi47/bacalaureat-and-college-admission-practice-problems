// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_042.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, v[100] = {};
    ifstream f("numere.txt");
    f >> n; // numarul de... numere
    while (f >> n)
        ++v[n];

    for (int i = 0; i < 100; ++i)
        if (v[i] == 1)
            cout << i << ' ';

    return 0;
}
