// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_078.pdf
// Problema 3

#include <iostream>

using namespace std;

void prim(int n, bool &p)
{
    if (n < 2)
    {
        p = false;
        return;
    }

    if (n % 2 == 0 && n != 2)
    {
        p = false;
        return;
    }

    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0)
        {
            p = false;
            return;
        }

    p = true;
}

int main()
{
    int n;
    cin >> n;
    int nr = 2;
    int cnt = 0;
    bool p;
    while (cnt < n)
    {
        prim(nr, p);
        if (p)
        {
            cout << nr << ' ';
            ++cnt;
        }
        ++nr;
    }

    return 0;
}
