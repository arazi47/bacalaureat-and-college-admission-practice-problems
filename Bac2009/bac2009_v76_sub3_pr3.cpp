// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_076.pdf
// Problema 3

#include <iostream>

using namespace std;

void s(int n, int c, int &k)
{
    k = 0;
    int uc; // ultima cifra
    while (n)
    {
        uc = n % 10;
        if (uc == c - 1 || uc == c || uc == c + 1)
            ++k;

        n /= 10;
    }
}

int main()
{
    int n, c, k;
    cin >> n >> c;
    s(n, c, k);
    cout << k;

    return 0;
}
