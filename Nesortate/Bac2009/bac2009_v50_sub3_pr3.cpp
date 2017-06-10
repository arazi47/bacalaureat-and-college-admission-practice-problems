// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_050.pdf
// Problema 3

#include <iostream>

using namespace std;

bool divxy(int x, int y)
{
    return (x % y == 0) || (y % x == 0);
}

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }

    bool areDivizori = false;
    // <= n, deoarece vrem doar numerele pana la n care se divid cu n
    while (a <= n)
    {
        if (divxy(a, n))
        {
            cout << a << ' ';
            if (!areDivizori)
                areDivizori = true;
        }

        ++a;
    }

    if (!areDivizori)
        cout << "NU EXISTA";

    return 0;
}
