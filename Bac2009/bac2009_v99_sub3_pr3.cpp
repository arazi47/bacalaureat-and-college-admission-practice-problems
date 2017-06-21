// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_099.pdf
// Problema 3

#include <iostream>

using namespace std;

void Nr(int &k)
{
    k /= 10;
    int r = 0, p = 1;
    while (k > 9)
    {
        r = r + p * (k % 10);
        p *= 10;
        k /= 10;
    }

    k = r;
}

int main()
{
    int n;
    cin >> n;
    Nr(n);
    cout << n;

    return 0;
}
