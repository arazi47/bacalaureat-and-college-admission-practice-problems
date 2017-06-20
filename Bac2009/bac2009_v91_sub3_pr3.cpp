// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_091.pdf
// Problema 3

#include <iostream>

using namespace std;

bool par(int n)
{
    while (n)
    {
        if ((n % 10) % 2 == 0)
            return true;

        n /= 10;
    }

    return false;
}

int main()
{
    int n, x;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (par(x) && !par(x / 10))
            ++cnt;
    }

    cout << cnt;

    return 0;
}
