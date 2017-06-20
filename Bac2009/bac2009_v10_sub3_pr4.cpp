// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_010.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

// produse.txt:
// 3 1 5
// 1 20 5
// 2 10 3
// 1 10 5
int main()
{
    ifstream f("produse.txt");
    int v[9999] = {};
    int i, coef1, coef2;
    while (f >> i >> coef1 >> coef2)
        v[i - 1] += (coef1 * coef2);

    for (int i = 0; i < 9999; ++i)
        if (v[i] > 0)
            cout << i + 1 << ' ' << v[i] << '\n';

    return 0;
}

