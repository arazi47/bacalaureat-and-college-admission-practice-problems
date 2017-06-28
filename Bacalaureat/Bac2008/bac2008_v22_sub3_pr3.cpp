// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_022.pdf

#include <iostream>

using namespace std;

int nz(int n)
{
    int cnt5 = 0, x;
    for (int i = 5; i <= n; i += 5)
    {
        x = i;
        while (x % 5 == 0)
        {
            ++cnt5;
            x /= 5;
        }
    }

    return cnt5;
}

int main()
{
    int k;
    cin >> k;
    int n = 0;
    while (nz(n) != k)
        ++n;

    cout << n;

    return 0;
}

