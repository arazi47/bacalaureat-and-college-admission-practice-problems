// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_040.pdf
// Problema 4

#include <iostream>

using namespace std;

int sdiv(int y)
{
    int sum = 0;
    int d;
    for (d = 1; d * d < y; ++d)
        if (y % d == 0)
            sum += (d + (y / d));

    if (d * d == y)
        sum += d;

    return sum;
}

bool prim(int n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0 && n != 2)
        return false;
    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    if (prim(sdiv(n)))
        cout << "DA";
    else
        cout << "NU";

    return 0;
}
