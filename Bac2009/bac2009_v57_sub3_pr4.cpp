// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_057.pdf
// Problema 4

#include <iostream>

using namespace std;

int multiplu(int a, int k)
{
    int nr = 1;
    while (nr <= a)
        nr *= k;

    return nr;
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (multiplu(x, z) <= y)
        cout << "DA";
    else
        cout << "NU";

    return 0;
}

