// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_032.pdf
// Problema 3

#include <iostream>

using namespace std;

int nr_prim(int n)
{
    bool prim;
    do
    {
        prim = true;
        ++n;
        if (n < 2)
            prim = false;
        if (n % 2 == 0 && n != 2 && prim)
            prim = false;
        for (int d = 3; d * d <= n; d += 2)
            if (n % d == 0)
                prim = false;

        if (prim)
            return n;

    } while (true);
}

int main()
{
    int n;
    cin >> n;
    cout << nr_prim(n);

    return 0;
}
