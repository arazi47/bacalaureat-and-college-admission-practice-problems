// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_068.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    ifstream f("str.txt");
    // numarul de elemente ale sirului
    f >> n;
    int lmax = 0;
    int a, b;
    f >> a;
    int lcurr = 1, elmax = a;
    while (f >> b)
    {
        if (a == b)
        {
            ++lcurr;
            a = b;
        }
        else
        {
            if (lcurr > lmax)
            {
                lmax = lcurr;
                elmax = a;
            }
            else if (lcurr == lmax && b > elmax)
                elmax = b;

            a = b;
            lcurr = 1;
        }
    }

    // ultima secventa
    if (lcurr == lmax && b > elmax)
        elmax = b;

    cout << lmax << ' ' << elmax;

    return 0;
}
