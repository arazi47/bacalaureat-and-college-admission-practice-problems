// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_086.pdf
// Problema 3

#include <iostream>

using namespace std;

int numar(int n, int c1, int c2)
{
    int r = 0, p = 1;
    while (n)
    {
        if (n % 10 == c1)
            r = r + p * c2;
        else
            r = r + p * (n % 10);

        p *= 10;
        n /= 10;
    }

    return r;
}

int main()
{
    int n, c1, c2;
    cin >> n >> c1 >> c2;
    cout << numar(n, c1, c2);

    return 0;
}
