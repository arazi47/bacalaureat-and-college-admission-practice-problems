// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_048.pdf
// Problema 3

#include <iostream>

using namespace std;

int cmdiv(int x, int y)
{
    int r;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main()
{
    int n, nrFractiiIreductibile = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (cmdiv(i, n) == 1)
            ++nrFractiiIreductibile;
    }

    cout << nrFractiiIreductibile;

    return 0;
}
