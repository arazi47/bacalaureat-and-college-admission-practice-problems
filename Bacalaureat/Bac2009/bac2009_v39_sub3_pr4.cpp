// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_039.pdf
// Problema 4

#include <iostream>

using namespace std;

bool pr(int a)
{
    if (a < 2)
        return false;
    if (a % 2 == 0 && a != 2)
        return false;
    for (int d = 3; d * d <= a; d += 2)
        if (a % d == 0)
            return false;
    return true;
}

int main()
{
    int a;
    cin >> a;
    a /= 10;
    while (a > 9)
    {
         if (pr(a))
            cout << a << ' ';
         a /= 10;
    }

    return 0;
}
