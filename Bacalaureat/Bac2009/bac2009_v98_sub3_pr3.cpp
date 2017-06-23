// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_098.pdf
// Problema 3

#include <iostream>

using namespace std;

int numar(int x, int y)
{
    int factor = x;
    int z = 1;
    while (x * factor < y)
    {
        x *= factor;
        ++z;
    }

    return z;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << numar(x, y);

    return 0;
}
