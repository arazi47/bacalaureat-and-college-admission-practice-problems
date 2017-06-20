// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_085.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int CMMDC(int x, int y)
{
    int r;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main()
{
    ifstream f("numere.in");
    int x, y, c;
    ofstream g("numere.out");
    while (f >> x >> y)
    {
        c = CMMDC(x, y);
        g << x / c << ' ' << y / c << endl;
    }

    return 0;
}
