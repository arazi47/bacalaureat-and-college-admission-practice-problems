// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_027.pdf
// Problema 3

#include <iostream>

using namespace std;

float nreal(int x, int y)
{
    float rez = x;

    int p = 1, cy = y;
    while (cy)
    {
        p *= 10;
        cy /= 10;
    }

    rez = rez + float(y) / p;

    return rez;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << nreal(x, y);

    return 0;
}

