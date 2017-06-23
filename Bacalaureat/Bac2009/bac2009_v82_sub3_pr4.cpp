// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_082.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, v[100] = {};
    ifstream f("numere.in");
    while (f >> n)
    {
        if (n <= 99)
            ++v[n];
    }

    ofstream g("numere.out");
    for (int i = 99; i >= 10; --i)
        if (v[i])
        {
            g << i << ' ' << v[i] << endl;
            break;
        }

    for (int i = 10; i <= 99; ++i)
        if (v[i])
        {
            g << i << ' ' << v[i] << endl;
            break;
        }

    return 0;
}
