// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_045.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int n, nr[100] = {};

    // numarul de numere ce vor fi citite
    f >> n;

    while (f >> n)
        ++nr[n];

    for (int i = 0; i < 100; ++i)
        while (nr[i])
        {
            cout << i << ' ';
            --nr[i];
        }

    return 0;
}
