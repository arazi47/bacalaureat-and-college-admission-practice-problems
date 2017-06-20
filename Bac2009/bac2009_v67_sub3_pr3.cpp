// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_067.pdf
// Problema 3

#include <iostream>

using namespace std;

int calcul(int n, int a[])
{
    bool prim;
    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        prim = true;
        if (a[i] < 2)
            prim = false;
        if (a[i] % 2 == 0 && a[i] != 2)
            prim = false;
        for (int d = 3; d * d <= a[i]; d += 2)
            if (a[i] % d == 0)
            {
                prim = false;
                break;
            }

        if (prim)
            ++cnt;
    }

    return cnt;
}

int main()
{
    int n, a[10000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << calcul(n, a);

    return 0;
}
