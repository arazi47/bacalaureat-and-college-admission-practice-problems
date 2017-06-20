// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_078.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int v[10] = {}, n;
    ifstream f("bac.in");
    f >> n;
    while (f >> n)
        ++v[n];

    for (int i = 9; i >= 0; --i)
        if (v[i])
            cout << i << ' ' << v[i] << endl;

    return 0;
}
