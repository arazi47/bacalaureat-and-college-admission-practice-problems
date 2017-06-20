// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_021.pdf
// Problema 3

#include <iostream>

using namespace std;

int i_prim(int n)
{
    int p1 = n, p2 = n;
    bool prim;
    do
    {
        prim = true;
        if (p1 < 2)
            prim = false;
        if (p1 % 2 == 0 && p1 != 2)
            prim = false;
        for (int d = 3; d * d <= p1; d += 2)
            if (p1 % d == 0)
                prim = false;

        if (prim)
            break;
        else
            --p1;
    } while (true);

    do
    {
        prim = true;
        if (p2 < 2)
            prim = false;
        if (p2 % 2 == 0 && p2 != 2)
            prim = false;
        for (int d = 3; d * d <= p2; d += 2)
            if (p2 % d == 0)
                prim = false;

        if (prim)
            break;
        else
            ++p2;
    } while (true);

    return p2 - p1;
}

int main()
{
    int n;
    cin >> n;
    cout << i_prim(n);

    return 0;
}

