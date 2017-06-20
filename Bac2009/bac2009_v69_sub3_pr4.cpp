// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_069.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int n;
    // numarul de elemente ale sirului
    f >> n;

    int v[10000], m = 0;
    while (f >> n)
    {
        if (n % 2)
            v[m++] = n;
        else
            cout << n << ' ';
    }

    for (int i = m - 1; i >= 0; --i)
        cout << v[i] << ' ';

    return 0;
}
