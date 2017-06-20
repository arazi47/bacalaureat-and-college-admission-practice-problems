// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_091.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.in");
    int maxLinieInceput, maxLinieSfarsit;
    float x;
    f >> x;
    int linie = 1;
    float max = x;
    maxLinieInceput = linie;
    while (f >> x)
    {
        ++linie;
        if (x > max)
        {
            max = x;
            maxLinieInceput = linie;
        }
        else if (x == max)
            maxLinieSfarsit = linie;
    }

    cout << maxLinieInceput << ' ' << maxLinieSfarsit;

    return 0;
}
