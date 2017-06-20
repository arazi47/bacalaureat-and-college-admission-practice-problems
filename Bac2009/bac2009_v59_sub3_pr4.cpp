// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_059.pdf
// Problema 4

#include <iostream>

using namespace std;

int divizor(int a)
{
    // este numar prim
    if (a == 2)
        return -1;

    for (int d = 2; d <= (a / 2) + 1; ++d)
        if (a % d == 0)
            return d;

    return -1;
}

int main()
{
    int x;
    cin >> x;
    // daca este numar prim
    if (divizor(x) == -1)
        cout << "DA";
    else
        cout << "NU";

    return 0;
}
