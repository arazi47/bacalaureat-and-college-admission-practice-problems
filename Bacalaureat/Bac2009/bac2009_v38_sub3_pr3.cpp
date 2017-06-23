// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_038.pdf
// Problema 3

#include <iostream>

using namespace std;

void Del(int &x, int y)
{
    int p = 1;
    int rez = 0;
    while (x)
    {
        if (x % 10 <= y)
        {
            rez = rez + p * (x % 10);
            p *= 10;
        }

        x /= 10;
    }

    if (rez == 0)
        x = -1;
    else
        x = rez;
}

int main()
{
    int x, y;
    cin >> x >> y;
    Del(x, y);
    cout << x;

    return 0;
}
