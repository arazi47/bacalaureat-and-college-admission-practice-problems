// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_060.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    bool v[9999 + 1] = {};
    ifstream f("bac.txt");
    int n;
    for (int i = 0; i < 100; ++i)
    {
        f >> n;
        if (!(v[n]))
            v[n] = true;
    }

    f >> n;
    if (v[n])
        cout << "DA";
    else
        cout << "NU";

    return 0;
}
