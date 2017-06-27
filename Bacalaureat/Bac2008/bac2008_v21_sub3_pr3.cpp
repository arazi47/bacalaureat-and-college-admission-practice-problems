// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_021.pdf

#include <iostream>

using namespace std;

int i_prim(int n)
{
    int p2, p1;
    bool prim;
    for (int i = n; ; --i)
    {
        prim = true;
        if (i < 2)
            prim = false;
        if (i % 2 == 0 && i != 2)
            prim = false;
        for (int d = 3; d * d <= i; ++d)
            if (i % d == 0)
            {
                prim = false;
                break;
            }

        if (prim)
        {
            p1 = i;
            break;
        }
    }

    for (int i = n; ; ++i)
    {
        prim = true;
        if (i < 2)
            prim = false;
        if (i % 2 == 0 && i != 2)
            prim = false;
        for (int d = 3; d * d <= i; ++d)
            if (i % d == 0)
            {
                prim = false;
                break;
            }

        if (prim)
        {
            p2 = i;
            break;
        }
    }

    return p2 - p1;
}

int main()
{
    int n;
    cin >> n;
    cout << i_prim(n);

    return 0;
}

