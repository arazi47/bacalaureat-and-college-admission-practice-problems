// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_019.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("nr1.txt");
    ifstream g("nr2.txt");

    int a, b;

    // marimile
    f >> a;
    g >> b;

    bool v[9999 + 1] = {};
    while (f >> a)
        if (!v[a])
            v[a] = true;

    while (g >> b)
        if (!v[b])
            v[b] = true;

    for (int i = 0; i < 9999 + 1; ++i)
        if (v[i])
            cout << i << ' ';

    return 0;
}

