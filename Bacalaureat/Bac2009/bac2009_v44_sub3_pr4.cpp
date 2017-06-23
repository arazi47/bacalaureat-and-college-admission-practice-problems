// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_044.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int n;
    bool v[10] = {};
    f >> n; // numarul de numere ce vor fi citite
    while (f >> n)
    {
        while (n)
        {
            if (!v[n % 10])
                v[n % 10] = true;
            n /= 10;
        }
    }

    for (int i = 0; i < 10; ++i)
        if (v[i])
            cout << i << ' ';

    return 0;
}
