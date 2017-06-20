// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_077.pdf
// Problema 3

#include <iostream>

using namespace std;

int main()
{
    int n, k, v[100], nrzecimale, cnt = 0;
    float x;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        nrzecimale = 0;
        while (x != int(x))
        {
            ++nrzecimale;
            x *= 10;
        }

        if (nrzecimale > k)
            ++cnt;
    }

    cout << cnt;

    return 0;
}
