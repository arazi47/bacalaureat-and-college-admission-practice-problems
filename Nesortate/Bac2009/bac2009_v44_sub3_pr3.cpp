// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_044.pdf
// Problema 3

#include <iostream>

using namespace std;

void P(int a, int b)
{
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }

    bool prim;
    do
    {
        prim = true;
        if (a < 2)
            prim = false;
        if (a % 2 == 0 && a != 2)
            prim = false;
        for (int d = 3; d * d <= a; d += 2)
            if (a % d == 0)
            {
                prim = false;
                break;
            }

        if (prim)
            cout << a * a << ' ';
        ++a;
    } while (a * a < b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    P(a, b);

    return 0;
}
