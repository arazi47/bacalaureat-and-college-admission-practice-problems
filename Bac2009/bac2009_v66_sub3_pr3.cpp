// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_066.pdf
// Problema 3

#include <iostream>

using namespace std;

int calcul(int n, int a[])
{
    int gcd = a[0], r, x, y;
    for (int i = 1; i < n; ++i)
    {
        x = gcd;
        y = a[i];
        while (y)
        {
            r = x % y;
            x = y;
            y = r;
        }

        gcd = x;
    }

    return gcd;
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
