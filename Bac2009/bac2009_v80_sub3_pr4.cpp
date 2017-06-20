// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_080.pdf
// Problema 4

#include <iostream>

using namespace std;

int divi(int n)
{
    if (n == 2)
        return 0;

    for (int d = 2; d <= (n / 2) + 1; ++d)
        if (n % d == 0)
            return d;

    return 0;
}

int main()
{
    int n;
    cin >> n;
    int div = divi(n);
    if (div == 0)
        cout << 1;
    else
        cout << n / div;

    return 0;
}
