// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_040.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.in");
    int n;
    f >> n;
    int x;
    int prevPar = 0, prevImpar = 9999 + 2;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        if (x % 2 == 0 && x <= prevPar)
        {
            cout << "NU";
            return 0;
        }
        else if (x % 2 == 0 && x > prevPar)
            prevPar = x;
        else if (x % 2 && x >= prevImpar)
        {
            cout << "NU";
            return 0;
        }
        else if (x % 2 && x < prevImpar)
            prevImpar = x;
    }

    cout << "DA";

    return 0;
}
