// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_088.pdf
// Problema 3

#include <iostream>

using namespace std;

void numar(int n, int c1, int c2, int &x)
{
    x = 0;
    int p = 1;
    while (n)
    {
        if (!((n % 10) >= c1 && (n % 10) <= c2))
        {
            x = x + p * (n % 10);
            p *= 10;
        }

        n /= 10;
    }
}

int main()
{
    int n, c1, c2, x;
    cin >> n >> c1 >> c2;
    numar(n, c1, c2, x);
    cout << x;

    return 0;
}
