// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_088.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int v[10] = {}, n;
    ifstream f("bac.txt");
    while (f >> n)
        ++v[n];

    if (v[7])
        cout << 7 << ' ' << v[7];
    else if (v[5])
        cout << 5 << ' ' << v[5];
    else if (v[3])
        cout << 3 << ' ' << v[3];
    else if (v[2])
        cout << 2 << ' ' << v[2];

    return 0;
}
