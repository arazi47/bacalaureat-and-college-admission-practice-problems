// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_053.pdf
// Problema 3

#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int n, cnt = 0;;
    cin >> n;
    for (int i = 2; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (cmmdc(i, j) == 1)
            {
                cout << i << ' ' << j << endl;
                ++cnt;
            }

    cout << cnt;

    return 0;
}
