// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_058.pdf
// Problema 4

#include <iostream>

using namespace std;

int divizor(int a)
{
    for (int d = a / 2; d >= 1; --d)
        if (a % d == 0)
            return d;
}

int main()
{
    int x;
    cin >> x;
    // daca e numar prim
    if (divizor(x) == 1)
        cout << "DA";
    else
        cout << "NU";

    return 0;
}
