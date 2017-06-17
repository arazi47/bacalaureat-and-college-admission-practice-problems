// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_070.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int n;
    // numarul de elemente
    f >> n;
    int a, b;
    f >> a;
    int cntmax = 1, elmax = a;
    int cntcurr = 1;
    for (int i = 1; i < n; ++i)
    {
        f >> b;
        if (a == b)
            ++cntcurr;
        else
        {
            if (cntcurr > cntmax)
            {
                cntmax = cntcurr;
                elmax = a;
            }
            else if (cntcurr == cntmax && a < elmax)
                elmax = a;

            cntcurr = 1;
        }

        a = b;
    }

    cout << elmax << ' ' << cntmax;

    return 0;
}
