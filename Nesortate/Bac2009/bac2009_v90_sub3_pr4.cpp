// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_090.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int diferenta(int a, int b)
{
    return a - b;
}

int main()
{
    ifstream f("bac.txt");
    int amax = 0, bmax = 0;
    int a, b;
    f >> a;
    while (f >> b)
    {
        if (a > 0 && b > 0 && diferenta(a, b) > diferenta(amax, bmax))
        {
            amax = a;
            bmax = b;
        }
        a = b;
    }

    cout << amax << ' ' << bmax;

    return 0;
}
